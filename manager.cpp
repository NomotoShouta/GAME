//==============================
//
//	マネージャー処理[Manager.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "manager.h"
#include "input.h"
#include "joypad.h"


// 静的メンバ初期化
CRenderer* CManager::m_pRnderer = nullptr;
CInputKeyboard* CManager::m_pKeyboard = nullptr;
CCamera* CManager::m_pCamera = nullptr;
CLight* CManager::m_pLight = nullptr;
CScene* CManager::m_pScene = nullptr;

//===========================================
// コンストラクタ
//===========================================
CManager::CManager()
{

}

//===========================================
// デストラクタ
//===========================================
CManager::~CManager()
{

}

//===========================================
// 初期設定
//===========================================
HRESULT CManager::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// レンダラーの生成
	m_pRnderer = new CRenderer();
	m_pRnderer->Init(hWnd, bWindow);

	// キーボードの生成
	m_pKeyboard = new CInputKeyboard();
	m_pKeyboard->Init(hInstance, hWnd);

	// カメラの生成
	m_pCamera = new CCamera();
	m_pCamera->Init();

	// ライトの生成
	m_pLight = new CLight();
	m_pLight->Init();

	SetScene(CScene::MODE::MODE_TITLE);

	////ジョイパットの初期化処理
	//if (FAILED(InitJoypad()))
	//{
	//	return E_FAIL;
	//}

	return S_OK;
}

//===========================================
// 終了処理
//===========================================
void CManager::Uninit()
{
	CObject::ReleaseAll();

	// レンダラー
	if (m_pRnderer != nullptr)
	{
		m_pRnderer->Uninit();
		delete m_pRnderer;
		m_pRnderer = nullptr;
	}

	// キーボード
	if (m_pKeyboard != nullptr)
	{
		m_pKeyboard->Uninit();
		delete m_pKeyboard;
		m_pKeyboard = nullptr;
	}

	// カメラ
	if (m_pCamera != nullptr)
	{
		m_pCamera->Uninit();
		delete m_pCamera;
		m_pCamera = nullptr;
	}

	// ライト
	if (m_pLight != nullptr)
	{

		m_pLight->Uninit();
		delete m_pLight;
		m_pLight = nullptr;
	}
}

//===========================================
// 更新処理
//===========================================
void CManager::Update()
{
	// レンダラー
	if (m_pRnderer != nullptr)
	{
		m_pRnderer->Update();
	}

	// キーボード
	if (m_pKeyboard != nullptr)
	{
		m_pKeyboard->Update();
	}

	// カメラ
	if (m_pCamera != nullptr)
	{
		m_pCamera->Update();
	}

	// ライト
	if (m_pLight != nullptr)
	{
		m_pLight->Update();
	}

	// scene
	if (m_pScene != nullptr)
	{
		m_pScene->Update();
	}


	
}

//===========================================
// 描画処理
//===========================================
void CManager::Draw()
{
	// レンダラー
	if (m_pRnderer != nullptr)
	{
		m_pRnderer->Draw();
	}
}

//===========================================
// レンダラー取得
//===========================================
CRenderer* CManager::GetRenderer()
{
	return m_pRnderer;
}

//===========================================
// キーボード取得
//===========================================
CInputKeyboard* CManager::GetKeyboard()
{
	return m_pKeyboard;
}

//===========================================
// カメラ取得
//===========================================
CCamera* CManager::GetCamera()
{
	return m_pCamera;
}

//===========================================
// ライト取得
//===========================================
CLight* CManager::GetLight()
{
	return m_pLight;
}

//===========================================
// セットモード
//===========================================
void CManager::SetScene(CScene::MODE mode)
{
	
	if (m_pScene != nullptr)
	{
		m_pScene->Uninit();
		

		delete m_pScene;
		m_pScene = nullptr;
	}

	m_pScene = CScene::Create(mode);
}