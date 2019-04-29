#include "GameApp.h"
#include "d3dUtil.h"
#include "DXTrace.h"
using namespace DirectX;
using namespace std::experimental;

GameApp::GameApp(HINSTANCE hInstance)
	: D3DApp(hInstance),
	m_CameraMode(CameraMode::Free),
	m_Eta(1.0f / 1.51f),
	m_SkyBoxMode(SkyBoxMode::Daylight),
	m_SphereMode(SphereMode::Reflection),
	hitObject(false),		//�Ӷ�
	ballstate(0),			//�Ӷ�
	canSee(true)
{
}

GameApp::~GameApp()
{
}

bool GameApp::Init()
{
	if (!D3DApp::Init())
		return false;

	// ����ȳ�ʼ��������Ⱦ״̬���Թ��������Чʹ��
	RenderStates::InitAll(m_pd3dDevice);

	if (!m_BasicEffect.InitAll(m_pd3dDevice))
		return false;

	if (!m_SkyEffect.InitAll(m_pd3dDevice))
		return false;

	if (!InitResource())
		return false;

	// ��ʼ����꣬���̲���Ҫ
	m_pMouse->SetWindow(m_hMainWnd);
	m_pMouse->SetMode(DirectX::Mouse::MODE_RELATIVE);

	//����
	
	return true;
}

bool GameApp::InitResource()
{
	// ******************
	// ��ʼ����պ����

	m_pDaylight = std::make_unique<DynamicSkyRender>(m_pd3dDevice, m_pd3dImmediateContext, L"Texture\\daylight222.jpg", 5000.0f, 256);

	m_BasicEffect.SetTextureCube(m_pDaylight->GetDynamicTextureCube());

	// ******************
	// ��ʼ����Ϸ����
	//

	Model model;
	// ����
	model.SetMesh(m_pd3dDevice, Geometry::CreateSphere(1.0f, 30, 30));
	model.modelParts[0].material.ambient = XMFLOAT4(0.2f, 0.2f, 0.2f, 1.0f);
	model.modelParts[0].material.diffuse = XMFLOAT4(0.5f, 0.5f, 0.5f, 1.0f);
	model.modelParts[0].material.specular = XMFLOAT4(0.8f, 0.8f, 0.8f, 16.0f);
	model.modelParts[0].material.Reflect = XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f);
	HR(CreateDDSTextureFromFile(m_pd3dDevice.Get(), L"Texture\\stone.dds", nullptr, model.modelParts[0].texDiffuse.GetAddressOf()));
	m_Sphere.SetModel(std::move(model));
	// ����
	model.SetMesh(m_pd3dDevice, Geometry::CreatePlane(XMFLOAT3(0.0f, -3.0f, 0.0f), XMFLOAT2(40.0f, 40.0f), XMFLOAT2(20.0f, 20.0f)));//ԭ��0��-3,0����16��16����8,8��
	model.modelParts[0].material.ambient = XMFLOAT4(0.2f, 0.2f, 0.2f, 1.0f);
	model.modelParts[0].material.diffuse = XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f);
	model.modelParts[0].material.specular = XMFLOAT4(0.2f, 0.2f, 0.2f, 16.0f);
	model.modelParts[0].material.Reflect = XMFLOAT4();
	HR(CreateDDSTextureFromFile(m_pd3dDevice.Get(), L"Texture\\floor.dds", nullptr, model.modelParts[0].texDiffuse.GetAddressOf()));
	m_Ground.SetModel(std::move(model));
	// ����
	model.SetMesh(m_pd3dDevice, Geometry::CreateCylinder(0.5f, 2.0f));
	model.modelParts[0].material.ambient = XMFLOAT4(0.2f, 0.2f, 0.2f, 1.0f);
	model.modelParts[0].material.diffuse = XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f);
	model.modelParts[0].material.specular = XMFLOAT4(0.2f, 0.2f, 0.2f, 16.0f);
	model.modelParts[0].material.Reflect = XMFLOAT4();
	HR(CreateDDSTextureFromFile(m_pd3dDevice.Get(), L"Texture\\bricks.dds", nullptr, model.modelParts[0].texDiffuse.GetAddressOf()));
	m_Cylinder.SetModel(std::move(model));

	//��Χ��
	m_boundingSphere.Center = XMFLOAT3(m_Sphere.GetPosition());
	m_boundingSphere.Radius = 0.5f;
	

	// ******************
	// ��ʼ�������
	//
	m_CameraMode = CameraMode::Free;
	auto camera = std::shared_ptr<FirstPersonCamera>(new FirstPersonCamera);
	m_pCamera = camera;
	camera->SetViewPort(0.0f, 0.0f, (float)m_ClientWidth, (float)m_ClientHeight);
	camera->SetFrustum(XM_PI / 3, AspectRatio(), 1.0f, 1000.0f);
	camera->LookTo(
		XMVectorSet(0.0f, 0.0f, -10.0f, 1.0f),
		XMVectorSet(0.0f, 0.0f, 1.0f, 1.0f),
		XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f));
	// ��ʼ�������¹۲����ͶӰ����(����������̶�)
	camera->UpdateViewMatrix();
	m_BasicEffect.SetViewMatrix(camera->GetViewXM());
	m_BasicEffect.SetProjMatrix(camera->GetProjXM());


	// ******************
	// ��ʼ������仯��ֵ
	//

	// �����
	DirectionalLight dirLight[4];
	dirLight[0].ambient = XMFLOAT4(0.15f, 0.15f, 0.15f, 1.0f);
	dirLight[0].diffuse = XMFLOAT4(0.3f, 0.3f, 0.3f, 1.0f);
	dirLight[0].specular = XMFLOAT4(0.1f, 0.1f, 0.1f, 1.0f);
	dirLight[0].direction = XMFLOAT3(-0.577f, -0.577f, 0.577f);
	dirLight[1] = dirLight[0];
	dirLight[1].direction = XMFLOAT3(0.577f, -0.577f, 0.577f);
	dirLight[2] = dirLight[0];
	dirLight[2].direction = XMFLOAT3(0.577f, -0.577f, -0.577f);
	dirLight[3] = dirLight[0];
	dirLight[3].direction = XMFLOAT3(-0.577f, -0.577f, -0.577f);
	for (int i = 0; i < 4; ++i)
		m_BasicEffect.SetDirLight(i, dirLight[i]);

	return true;
}

void GameApp::OnResize()
{
	assert(m_pd2dFactory);
	assert(m_pdwriteFactory);
	// �ͷ�D2D�������Դ
	m_pColorBrush.Reset();
	m_pd2dRenderTarget.Reset();

	D3DApp::OnResize();

	// ΪD2D����DXGI������ȾĿ��
	ComPtr<IDXGISurface> surface;
	HR(m_pSwapChain->GetBuffer(0, __uuidof(IDXGISurface), reinterpret_cast<void**>(surface.GetAddressOf())));
	D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(
		D2D1_RENDER_TARGET_TYPE_DEFAULT,
		D2D1::PixelFormat(DXGI_FORMAT_UNKNOWN, D2D1_ALPHA_MODE_PREMULTIPLIED));
	HRESULT hr = m_pd2dFactory->CreateDxgiSurfaceRenderTarget(surface.Get(), &props, m_pd2dRenderTarget.GetAddressOf());
	surface.Reset();

	if (hr == E_NOINTERFACE)
	{
		OutputDebugString(L"\n���棺Direct2D��Direct3D�������Թ������ޣ��㽫�޷������ı���Ϣ�����ṩ������ѡ������\n"
			"1. ����Win7ϵͳ����Ҫ������Win7 SP1������װKB2670838������֧��Direct2D��ʾ��\n"
			"2. �������Direct3D 10.1��Direct2D�Ľ�����������ģ�"
			"https://docs.microsoft.com/zh-cn/windows/desktop/Direct2D/direct2d-and-direct3d-interoperation-overview""\n"
			"3. ʹ�ñ������⣬����FreeType��\n\n");
	}
	else if (hr == S_OK)
	{
		// �����̶���ɫˢ���ı���ʽ
		HR(m_pd2dRenderTarget->CreateSolidColorBrush(
			D2D1::ColorF(D2D1::ColorF::White),
			m_pColorBrush.GetAddressOf()));
		HR(m_pdwriteFactory->CreateTextFormat(L"����", nullptr, DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 15, L"zh-cn",
			m_pTextFormat.GetAddressOf()));
	}
	else
	{
		// �����쳣����
		assert(m_pd2dRenderTarget);
	}

	// ����������ʾ
	if (m_pCamera != nullptr)
	{
		m_pCamera->SetFrustum(XM_PI / 3, AspectRatio(), 1.0f, 1000.0f);
		m_pCamera->SetViewPort(0.0f, 0.0f, (float)m_ClientWidth, (float)m_ClientHeight);
		m_BasicEffect.SetProjMatrix(m_pCamera->GetProjXM());
	}
}

void GameApp::UpdateScene(float dt)
{

	// ��������¼�����ȡ���ƫ����
	Mouse::State mouseState = m_pMouse->GetState();
	Mouse::State lastMouseState = m_MouseTracker.GetLastState();
	m_MouseTracker.Update(mouseState);

	Keyboard::State keyState = m_pKeyboard->GetState();
	m_KeyboardTracker.Update(keyState);

	auto cam1st = std::dynamic_pointer_cast<FirstPersonCamera>(m_pCamera);

	// ********************
	// ����������Ĳ���
	//

	// �����ƶ�
	if (keyState.IsKeyDown(Keyboard::W))
		cam1st->MoveForward(dt * 6.0f);
	if (keyState.IsKeyDown(Keyboard::S))
		cam1st->MoveForward(dt * -6.0f);
	if (keyState.IsKeyDown(Keyboard::A))
		cam1st->Strafe(dt * -6.0f);
	if (keyState.IsKeyDown(Keyboard::D))
		cam1st->Strafe(dt * 6.0f);

	// ��Ұ��ת����ֹ��ʼ�Ĳ�ֵ�����µ�ͻȻ��ת
	cam1st->Pitch(mouseState.y * dt * 1.25f);
	cam1st->RotateY(mouseState.x * dt * 1.25f);

	// ����������
	XMFLOAT3 adjustedPos;
	XMStoreFloat3(&adjustedPos, XMVectorClamp(cam1st->GetPositionXM(), XMVectorSet(-20.0f, 0.0f, -20.0f, 0.0f), XMVectorSet(20.0f, 0.0f, 20.0f, 0.0f)));
	cam1st->SetPosition(adjustedPos);

	// ���¹۲����
	m_pCamera->UpdateViewMatrix();
	m_BasicEffect.SetViewMatrix(m_pCamera->GetViewXM());
	m_BasicEffect.SetEyePos(m_pCamera->GetPositionXM());

	// ѡ�������Ⱦģʽ
	if (m_KeyboardTracker.IsKeyPressed(Keyboard::D4))
	{
		m_SphereMode = SphereMode::None;
	}
	if (m_KeyboardTracker.IsKeyPressed(Keyboard::D5))
	{
		m_SphereMode = SphereMode::Reflection;
	}
	if (m_KeyboardTracker.IsKeyPressed(Keyboard::D6))
	{
		m_SphereMode = SphereMode::Refraction;
	}
	
	// ���ֵ���������
	m_Eta += mouseState.scrollWheelValue / 12000.0f;
	if (m_Eta > 1.0f)
	{
		m_Eta = 1.0f;
	}
	else if (m_Eta <= 0.2f)
	{
		m_Eta = 0.2f;
	}
	m_BasicEffect.SetRefractionEta(m_Eta);
		
	// ���ù���ֵ
	m_pMouse->ResetScrollWheelValue();

	// �˳���������Ӧ�򴰿ڷ���������Ϣ
	if (m_KeyboardTracker.IsKeyPressed(Keyboard::Escape))
		SendMessage(MainWnd(), WM_DESTROY, 0, 0);

	//����
	if (hitObject == true&& m_MouseTracker.leftButton == Mouse::ButtonStateTracker::PRESSED)ballstate = 1;

	//ʰȡ
	Ray ray = Ray::ScreenToRay(*m_pCamera, (float)mouseState.x, (float)mouseState.y);
	if (ray.Hit(m_Sphere.GetBoundingOrientedBox()) && m_MouseTracker.leftButton == Mouse::ButtonStateTracker::PRESSED)
	{
		hitObject = true;
	}

	m_boundingSphere.Center = m_Sphere.GetPosition();
	m_boundingSphere.Radius = 0.1f;

	if (ballstate == 1 &&m_boundingSphere.Contains(m_Cylinder.GetBoundingOrientedBox()))
	{
		canSee=false;
	}
}

void GameApp::DrawScene()
{
	assert(m_pd3dImmediateContext);
	assert(m_pSwapChain);

	// ******************
	// ���ɶ�̬��պ�
	//

	// ������ǰ���Ƶ���ȾĿ����ͼ�����ģ����ͼ
	m_pDaylight->Cache(m_pd3dImmediateContext, m_BasicEffect);


	// ���ƶ�̬��պе�ÿ���棨������Ϊ���ģ�
	for (int i = 0; i < 6; ++i)
	{
		m_pDaylight->BeginCapture(m_pd3dImmediateContext, m_BasicEffect, XMFLOAT3(), static_cast<D3D11_TEXTURECUBE_FACE>(i));
		DrawScene(false);
	}

	m_pDaylight->Restore(m_pd3dImmediateContext, m_BasicEffect, *m_pCamera); 
	
	// ******************
	// ���Ƴ���
	//

	// Ԥ�����
	m_pd3dImmediateContext->ClearRenderTargetView(m_pRenderTargetView.Get(), reinterpret_cast<const float*>(&Colors::Black));
	m_pd3dImmediateContext->ClearDepthStencilView(m_pDepthStencilView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

	DrawScene(true);

	// ******************
	// ����Direct2D����
	//
	if (m_pd2dRenderTarget != nullptr)
	{
		m_pd2dRenderTarget->BeginDraw();
		std::wstring text = L"(+)";
		m_pd2dRenderTarget->DrawTextW(text.c_str(), (UINT32)text.length(), m_pTextFormat.Get(),
			D2D1_RECT_F{ 390.0f, 280.0f, 1000.0f, 1000.0f }, m_pColorBrush.Get());
		HR(m_pd2dRenderTarget->EndDraw());
	}
	HR(m_pSwapChain->Present(0, 0));
}

void GameApp::DrawScene(bool drawCenterSphere)
{
	// ����ģ��
	m_BasicEffect.SetRenderDefault(m_pd3dImmediateContext, BasicEffect::RenderObject);

	m_BasicEffect.SetTextureUsed(true);

	// ���Ƶ���
	m_BasicEffect.SetReflectionEnabled(false);
	m_BasicEffect.SetRefractionEnabled(false);
	m_Ground.Draw(m_pd3dImmediateContext, m_BasicEffect);

	// ����1��Բ��
	m_BasicEffect.SetReflectionEnabled(false);
	m_BasicEffect.SetTextureUsed(true);
	
	m_Cylinder.SetWorldMatrix(
		XMMatrixTranslation(1.0f, -1.99f, 1.0f)
	);
	if(canSee)m_Cylinder.Draw(m_pd3dImmediateContext, m_BasicEffect);
	
	
	
	// ����Բ��
	// ʰȡǰ
	if (hitObject==false)
	{
		m_BasicEffect.SetReflectionEnabled(true);
		m_BasicEffect.SetRefractionEnabled(false);

		static float rad = 0.0f;
		rad += 0.001f;
		m_Sphere.SetWorldMatrix(

			XMMatrixScaling(0.5f, 0.5f, 0.5f) * XMMatrixTranslation(2.5f * XMScalarCos(rad), 0.0f, 2.5f * XMScalarSin(rad))
			);
		if (canSee)m_Sphere.Draw(m_pd3dImmediateContext, m_BasicEffect);
	}
	// ʰȡ��
	if (hitObject==true&&ballstate==0)
	{
		m_BasicEffect.SetReflectionEnabled(true);
		m_BasicEffect.SetRefractionEnabled(false);
	
		m_Sphere.SetWorldMatrix(
			
			XMMatrixScaling(0.5f, 0.5f, 0.5f)*XMMatrixTranslationFromVector(m_pCamera->GetPositionXM()+m_pCamera->GetLookXM())*XMMatrixTranslationFromVector(m_pCamera->GetLookXM())
		);
		
		if (canSee)m_Sphere.Draw(m_pd3dImmediateContext, m_BasicEffect);
	};
	//���
	if (ballstate==1)
	{
		m_BasicEffect.SetReflectionEnabled(true);
		m_BasicEffect.SetRefractionEnabled(false);

		static float rad = 0.0f;
		static float rad22 = 0.0f;
		rad += 0.01f;
		rad22 += 0.003f;
		static  XMVECTOR Temp=m_pCamera->GetLookXM();//temp forever
				XMVECTOR Temp2 = XMVectorSet(0.0f, -0.2f,0.0f,0.0f);

		m_Sphere.SetWorldMatrix(
				XMMatrixScaling(0.5f, 0.5f, 0.5f) * XMMatrixTranslationFromVector(m_pCamera->GetPositionXM() + m_pCamera->GetLookXM()) * XMMatrixTranslationFromVector(rad*Temp) * XMMatrixTranslationFromVector(rad22*rad22*Temp2)
				);
		
		if (canSee)m_Sphere.Draw(m_pd3dImmediateContext, m_BasicEffect);
	};


	// ������պ�
	m_SkyEffect.SetRenderDefault(m_pd3dImmediateContext);
	m_pDaylight->Draw(m_pd3dImmediateContext, m_SkyEffect, (drawCenterSphere ? *m_pCamera : m_pDaylight->GetCamera()));


}







