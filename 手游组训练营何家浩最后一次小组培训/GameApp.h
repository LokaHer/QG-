#ifndef GAMEAPP_H
#define GAMEAPP_H

#include "d3dApp.h"
#include "Camera.h"
#include "GameObject.h"
#include "SkyRender.h"
#include "ObjReader.h"
#include "Collision.h"

#include <DirectXCollision.h>

#include<iostream>
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;



class GameApp : public D3DApp
{
public:
	// �����ģʽ
	enum class CameraMode { FirstPerson, ThirdPerson, Free };
	// ��պ�ģʽ
	enum class SkyBoxMode { Daylight };
	// ���嵱ǰģʽ
	enum class SphereMode { None, Reflection, Refraction };

public:
	GameApp(HINSTANCE hInstance);
	~GameApp();

	bool Init();
	void OnResize();
	void UpdateScene(float dt);
	void DrawScene();


	bool hitObject;												//��ӵ�ʰȡ�ж�
	int ballstate;												//��ӵ�����ж�	
	bool canSee;

private:
	bool InitResource();
	
	void DrawScene(bool drawCenterSphere);

private:
	
	ComPtr<ID2D1SolidColorBrush> m_pColorBrush;				    // ��ɫ��ˢ
	ComPtr<IDWriteFont> m_pFont;								// ����
	ComPtr<IDWriteTextFormat> m_pTextFormat;					// �ı���ʽ

	GameObject m_Sphere;										// ��
	DirectX::BoundingSphere m_boundingSphere;

	GameObject m_Ground;										// ����
	GameObject m_Cylinder;									    // Բ��
	


	BasicEffect m_BasicEffect;								    // ������Ⱦ��Ч����
	SkyEffect m_SkyEffect;									    // ��պ���Ч����
	
	std::unique_ptr<DynamicSkyRender> m_pDaylight;			    // ��պ�(����)

	SkyBoxMode m_SkyBoxMode;									// ��պ�ģʽ

	SphereMode m_SphereMode;									// ����Ⱦģʽ
	float m_Eta;												// ����/����������


	std::shared_ptr<Camera> m_pCamera;						    // �����
	CameraMode m_CameraMode;									// �����ģʽ

	ObjReader m_ObjReader;									    // ģ�Ͷ�ȡ����
};


#endif