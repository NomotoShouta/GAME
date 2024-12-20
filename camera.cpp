
//==============================
//
// カメラ処理[camera.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "camera.h"
#include "object.h"
#include "renderer.h"
#include "main.h"
#include "manager.h"
#include "Player.h"
#include "keyboard.h"
#include "input.h"

//===========================================
// コンストラクタ
//===========================================
CCamera::CCamera()
{

}

//===========================================
// デストラクタ
//===========================================
CCamera::~CCamera()
{

}

//===========================================
// 初期化処理
//===========================================
HRESULT CCamera::Init()
{
	// メンバ変数の初期設定
	m_posV = D3DXVECTOR3(0.0f, 800.0f, -300.0f);	
	m_posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		
	m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);	
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_mtxProjection;				
	m_mtxView;						
	m_fLength = 250.0f;
	follow = false;

	return S_OK;
}

//===========================================
//終了処理
//===========================================
void CCamera::Uninit()
{

}

//===========================================
// 更新処理
//===========================================
void CCamera::Update()
{
	
}

//===========================================
// 設定処理
//===========================================
void CCamera::SetCamera()
{
	// プロジェクションマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxProjection);

	D3DXMatrixPerspectiveFovLH(&m_mtxProjection,
		D3DXToRadian(45.0f),
		(float)SCREEN_WIDTH / (float)SCREEN_HEIGHT,
		10.0f,
		1000.0f);

	// デバイスの取得
	CRenderer* pRenderer = CManager::GetRenderer();			
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();		

	// プロジェクションマトリックスの設定
	pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection);

	// ビューマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxView);

	// ビューマトリックスの作成
	D3DXMatrixLookAtLH(&m_mtxView,
		&m_posV, &m_posR, &m_vecU);

	// ビューマトリックスを設定する
	pDevice->SetTransform(D3DTS_VIEW, &m_mtxView);
}
