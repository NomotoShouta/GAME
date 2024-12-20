//==============================
//
// チュートリアル処理[tutorial.cpp]
// Author:Nomoto Shouta
//
//==============================

#include "tutorial.h"
#include "object.h"
#include "object2D.h"
#include "renderer.h"
#include "manager.h"
#include "keyboard.h"
#include "input.h"
#include "texture.h"

//===========================================
// コンストラクタ
//===========================================
CTutorial::CTutorial()
{

}

//===========================================
// デストラクタ
//===========================================
CTutorial::~CTutorial()
{

}

//===========================================
// 初期設定
//===========================================
HRESULT CTutorial::Init()
{
	

	LPDIRECT3DDEVICE9 pDevice;

	CRenderer* pRenderer = CManager::GetRenderer();

	//デバイスの取得
	pDevice = pRenderer->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\チュートリアル.png",
		&m_pTexture);

	CBg_re::Create();

	return S_OK;
}

//===========================================
// 終了処理
//===========================================
void CTutorial::Uninit()
{
	CScene::Uninit();
}

//===========================================
// 更新処理
//===========================================
void CTutorial::Update()
{
	if (m_Keyboard->GetTrigger(DIK_SPACE) == true)
	{
		CManager::SetScene(CScene::MODE_TITLE);
	}
}

//===========================================
// 描画処理
//===========================================
void CTutorial::Draw()
{
	LPDIRECT3DDEVICE9 pDevice;

	CRenderer* pRenderer = CManager::GetRenderer();

	//デバイスの取得
	pDevice = pRenderer->GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	//テクスチャの設定
	pDevice->SetTexture(0, m_pTexture);

	//ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

//===========================================
// 生成処理
//===========================================
CTutorial* CTutorial::Create(MODE mode)
{
	// 生成する
	CTutorial* pResult = new CTutorial;
	pResult->Init();

	return pResult;
}