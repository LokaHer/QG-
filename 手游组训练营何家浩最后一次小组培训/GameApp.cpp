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
	hitObject(false),		//加多
	ballstate(0),			//加多
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

	// 务必先初始化所有渲染状态，以供下面的特效使用
	RenderStates::InitAll(m_pd3dDevice);

	if (!m_BasicEffect.InitAll(m_pd3dDevice))
		return false;

	if (!m_SkyEffect.InitAll(m_pd3dDevice))
		return false;

	if (!InitResource())
		return false;

	// 初始化鼠标，键盘不需要
	m_pMouse->SetWindow(m_hMainWnd);
	m_pMouse->SetMode(DirectX::Mouse::MODE_RELATIVE);

	//音乐
	
	return true;
}

bool GameApp::InitResource()
{
	// ******************
	// 初始化天空盒相关

	m_pDaylight = std::make_unique<DynamicSkyRender>(m_pd3dDevice, m_pd3dImmediateContext, L"Texture\\daylight222.jpg", 5000.0f, 256);

	m_BasicEffect.SetTextureCube(m_pDaylight->GetDynamicTextureCube());

	// ******************
	// 初始化游戏对象
	//

	Model model;
	// 球体
	model.SetMesh(m_pd3dDevice, Geometry::CreateSphere(1.0f, 30, 30));
	model.modelParts[0].material.ambient = XMFLOAT4(0.2f, 0.2f, 0.2f, 1.0f);
	model.modelParts[0].material.diffuse = XMFLOAT4(0.5f, 0.5f, 0.5f, 1.0f);
	model.modelParts[0].material.specular = XMFLOAT4(0.8f, 0.8f, 0.8f, 16.0f);
	model.modelParts[0].material.Reflect = XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f);
	HR(CreateDDSTextureFromFile(m_pd3dDevice.Get(), L"Texture\\stone.dds", nullptr, model.modelParts[0].texDiffuse.GetAddressOf()));
	m_Sphere.SetModel(std::move(model));
	// 地面
	model.SetMesh(m_pd3dDevice, Geometry::CreatePlane(XMFLOAT3(0.0f, -3.0f, 0.0f), XMFLOAT2(40.0f, 40.0f), XMFLOAT2(20.0f, 20.0f)));//原（0，-3,0）（16，16）（8,8）
	model.modelParts[0].material.ambient = XMFLOAT4(0.2f, 0.2f, 0.2f, 1.0f);
	model.modelParts[0].material.diffuse = XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f);
	model.modelParts[0].material.specular = XMFLOAT4(0.2f, 0.2f, 0.2f, 16.0f);
	model.modelParts[0].material.Reflect = XMFLOAT4();
	HR(CreateDDSTextureFromFile(m_pd3dDevice.Get(), L"Texture\\floor.dds", nullptr, model.modelParts[0].texDiffuse.GetAddressOf()));
	m_Ground.SetModel(std::move(model));
	// 柱体
	model.SetMesh(m_pd3dDevice, Geometry::CreateCylinder(0.5f, 2.0f));
	model.modelParts[0].material.ambient = XMFLOAT4(0.2f, 0.2f, 0.2f, 1.0f);
	model.modelParts[0].material.diffuse = XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f);
	model.modelParts[0].material.specular = XMFLOAT4(0.2f, 0.2f, 0.2f, 16.0f);
	model.modelParts[0].material.Reflect = XMFLOAT4();
	HR(CreateDDSTextureFromFile(m_pd3dDevice.Get(), L"Texture\\bricks.dds", nullptr, model.modelParts[0].texDiffuse.GetAddressOf()));
	m_Cylinder.SetModel(std::move(model));

	//包围盒
	m_boundingSphere.Center = XMFLOAT3(m_Sphere.GetPosition());
	m_boundingSphere.Radius = 0.5f;
	

	// ******************
	// 初始化摄像机
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
	// 初始化并更新观察矩阵、投影矩阵(摄像机将被固定)
	camera->UpdateViewMatrix();
	m_BasicEffect.SetViewMatrix(camera->GetViewXM());
	m_BasicEffect.SetProjMatrix(camera->GetProjXM());


	// ******************
	// 初始化不会变化的值
	//

	// 方向光
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
	// 释放D2D的相关资源
	m_pColorBrush.Reset();
	m_pd2dRenderTarget.Reset();

	D3DApp::OnResize();

	// 为D2D创建DXGI表面渲染目标
	ComPtr<IDXGISurface> surface;
	HR(m_pSwapChain->GetBuffer(0, __uuidof(IDXGISurface), reinterpret_cast<void**>(surface.GetAddressOf())));
	D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(
		D2D1_RENDER_TARGET_TYPE_DEFAULT,
		D2D1::PixelFormat(DXGI_FORMAT_UNKNOWN, D2D1_ALPHA_MODE_PREMULTIPLIED));
	HRESULT hr = m_pd2dFactory->CreateDxgiSurfaceRenderTarget(surface.Get(), &props, m_pd2dRenderTarget.GetAddressOf());
	surface.Reset();

	if (hr == E_NOINTERFACE)
	{
		OutputDebugString(L"\n警告：Direct2D与Direct3D互操作性功能受限，你将无法看到文本信息。现提供下述可选方法：\n"
			"1. 对于Win7系统，需要更新至Win7 SP1，并安装KB2670838补丁以支持Direct2D显示。\n"
			"2. 自行完成Direct3D 10.1与Direct2D的交互。详情参阅："
			"https://docs.microsoft.com/zh-cn/windows/desktop/Direct2D/direct2d-and-direct3d-interoperation-overview""\n"
			"3. 使用别的字体库，比如FreeType。\n\n");
	}
	else if (hr == S_OK)
	{
		// 创建固定颜色刷和文本格式
		HR(m_pd2dRenderTarget->CreateSolidColorBrush(
			D2D1::ColorF(D2D1::ColorF::White),
			m_pColorBrush.GetAddressOf()));
		HR(m_pdwriteFactory->CreateTextFormat(L"宋体", nullptr, DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 15, L"zh-cn",
			m_pTextFormat.GetAddressOf()));
	}
	else
	{
		// 报告异常问题
		assert(m_pd2dRenderTarget);
	}

	// 摄像机变更显示
	if (m_pCamera != nullptr)
	{
		m_pCamera->SetFrustum(XM_PI / 3, AspectRatio(), 1.0f, 1000.0f);
		m_pCamera->SetViewPort(0.0f, 0.0f, (float)m_ClientWidth, (float)m_ClientHeight);
		m_BasicEffect.SetProjMatrix(m_pCamera->GetProjXM());
	}
}

void GameApp::UpdateScene(float dt)
{

	// 更新鼠标事件，获取相对偏移量
	Mouse::State mouseState = m_pMouse->GetState();
	Mouse::State lastMouseState = m_MouseTracker.GetLastState();
	m_MouseTracker.Update(mouseState);

	Keyboard::State keyState = m_pKeyboard->GetState();
	m_KeyboardTracker.Update(keyState);

	auto cam1st = std::dynamic_pointer_cast<FirstPersonCamera>(m_pCamera);

	// ********************
	// 自由摄像机的操作
	//

	// 方向移动
	if (keyState.IsKeyDown(Keyboard::W))
		cam1st->MoveForward(dt * 6.0f);
	if (keyState.IsKeyDown(Keyboard::S))
		cam1st->MoveForward(dt * -6.0f);
	if (keyState.IsKeyDown(Keyboard::A))
		cam1st->Strafe(dt * -6.0f);
	if (keyState.IsKeyDown(Keyboard::D))
		cam1st->Strafe(dt * 6.0f);

	// 视野旋转，防止开始的差值过大导致的突然旋转
	cam1st->Pitch(mouseState.y * dt * 1.25f);
	cam1st->RotateY(mouseState.x * dt * 1.25f);

	// 不允许穿地天
	XMFLOAT3 adjustedPos;
	XMStoreFloat3(&adjustedPos, XMVectorClamp(cam1st->GetPositionXM(), XMVectorSet(-20.0f, 0.0f, -20.0f, 0.0f), XMVectorSet(20.0f, 0.0f, 20.0f, 0.0f)));
	cam1st->SetPosition(adjustedPos);

	// 更新观察矩阵
	m_pCamera->UpdateViewMatrix();
	m_BasicEffect.SetViewMatrix(m_pCamera->GetViewXM());
	m_BasicEffect.SetEyePos(m_pCamera->GetPositionXM());

	// 选择球的渲染模式
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
	
	// 滚轮调整折射率
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
		
	// 重置滚轮值
	m_pMouse->ResetScrollWheelValue();

	// 退出程序，这里应向窗口发送销毁信息
	if (m_KeyboardTracker.IsKeyPressed(Keyboard::Escape))
		SendMessage(MainWnd(), WM_DESTROY, 0, 0);

	//发射
	if (hitObject == true&& m_MouseTracker.leftButton == Mouse::ButtonStateTracker::PRESSED)ballstate = 1;

	//拾取
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
	// 生成动态天空盒
	//

	// 保留当前绘制的渲染目标视图和深度模板视图
	m_pDaylight->Cache(m_pd3dImmediateContext, m_BasicEffect);


	// 绘制动态天空盒的每个面（以球体为中心）
	for (int i = 0; i < 6; ++i)
	{
		m_pDaylight->BeginCapture(m_pd3dImmediateContext, m_BasicEffect, XMFLOAT3(), static_cast<D3D11_TEXTURECUBE_FACE>(i));
		DrawScene(false);
	}

	m_pDaylight->Restore(m_pd3dImmediateContext, m_BasicEffect, *m_pCamera); 
	
	// ******************
	// 绘制场景
	//

	// 预先清空
	m_pd3dImmediateContext->ClearRenderTargetView(m_pRenderTargetView.Get(), reinterpret_cast<const float*>(&Colors::Black));
	m_pd3dImmediateContext->ClearDepthStencilView(m_pDepthStencilView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

	DrawScene(true);

	// ******************
	// 绘制Direct2D部分
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
	// 绘制模型
	m_BasicEffect.SetRenderDefault(m_pd3dImmediateContext, BasicEffect::RenderObject);

	m_BasicEffect.SetTextureUsed(true);

	// 绘制地面
	m_BasicEffect.SetReflectionEnabled(false);
	m_BasicEffect.SetRefractionEnabled(false);
	m_Ground.Draw(m_pd3dImmediateContext, m_BasicEffect);

	// 绘制1个圆柱
	m_BasicEffect.SetReflectionEnabled(false);
	m_BasicEffect.SetTextureUsed(true);
	
	m_Cylinder.SetWorldMatrix(
		XMMatrixTranslation(1.0f, -1.99f, 1.0f)
	);
	if(canSee)m_Cylinder.Draw(m_pd3dImmediateContext, m_BasicEffect);
	
	
	
	// 绘制圆球
	// 拾取前
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
	// 拾取后
	if (hitObject==true&&ballstate==0)
	{
		m_BasicEffect.SetReflectionEnabled(true);
		m_BasicEffect.SetRefractionEnabled(false);
	
		m_Sphere.SetWorldMatrix(
			
			XMMatrixScaling(0.5f, 0.5f, 0.5f)*XMMatrixTranslationFromVector(m_pCamera->GetPositionXM()+m_pCamera->GetLookXM())*XMMatrixTranslationFromVector(m_pCamera->GetLookXM())
		);
		
		if (canSee)m_Sphere.Draw(m_pd3dImmediateContext, m_BasicEffect);
	};
	//射出
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


	// 绘制天空盒
	m_SkyEffect.SetRenderDefault(m_pd3dImmediateContext);
	m_pDaylight->Draw(m_pd3dImmediateContext, m_SkyEffect, (drawCenterSphere ? *m_pCamera : m_pDaylight->GetCamera()));


}







