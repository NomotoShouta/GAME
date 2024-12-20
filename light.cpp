//==============================
//
// ライト処理[light.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "light.h"
#include "object.h"
#include "renderer.h"
#include "main.h"
#include "manager.h"

//===========================================
// コンストラクタ
//===========================================
CLight::CLight()
{
	
}

//===========================================
// デストラクタ
//===========================================
CLight::~CLight()
{

}

//===========================================
// 初期化処理
//===========================================
void CLight::Init()
{
	// デバイスを取得する
	CRenderer* pRenderer = CManager::GetRenderer();		
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	int nCntLight;

	D3DXVECTOR3 vecDir;

	m_aLight[0].vecDir = D3DXVECTOR3(0.5f, -0.9f, 0.5f);
	m_aLight[1].vecDir = D3DXVECTOR3(-0.2f, 0.9f, -0.5f);
	m_aLight[2].vecDir = D3DXVECTOR3(0.9f, 0.1f, 0.5f);

	for (nCntLight = 0; nCntLight < CLight::MAX; nCntLight++)
	{
		// ライトの情報をクリアする
		ZeroMemory(&m_aLight[nCntLight].light, sizeof(D3DLIGHT9));

		// ライトの種類を設定
		m_aLight[nCntLight].light.Type = D3DLIGHT_DIRECTIONAL;   

		// ライトの拡散光を設定
		m_aLight[nCntLight].light.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);   

		// ライトの方向を設定
		vecDir = m_aLight[nCntLight].vecDir;
		D3DXVec3Normalize(&vecDir, &vecDir);
		m_aLight[nCntLight].light.Direction = vecDir;

		// ライトを設定する
		pDevice->SetLight(nCntLight, &m_aLight[nCntLight].light);

		// ライトを有効にする
		pDevice->LightEnable(nCntLight, TRUE);
	}
}

//===========================================
//終了処理
//===========================================
void CLight::Uninit()
{

}

//===========================================
//更新処理
//===========================================
void CLight::Update()
{

}