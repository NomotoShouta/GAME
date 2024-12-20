//==============================
//
// リザルト処理[result.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "result.h"
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
CResult::CResult()
{

}

//===========================================
// デストラクタ
//===========================================
CResult::~CResult()
{

}

//===========================================
// 初期設定
//===========================================
HRESULT CResult::Init()
{
	m_Keyboard = CManager::GetKeyboard();

	LPDIRECT3DDEVICE9 pDevice;		

	CRenderer* pRenderer = CManager::GetRenderer();

	//デバイスの取得
	pDevice = pRenderer->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\bg003.jpg",
		&m_pTexture);

	CBg_re::Create();

	return S_OK;
}

//===========================================
// 終了処理
//===========================================
void CResult::Uninit()
{
	CScene::Uninit();
}

//===========================================
// 更新処理
//===========================================
void CResult::Update()
{
	if (m_Keyboard->GetTrigger(DIK_SPACE) == true)
	{
		CManager::SetScene(CScene::MODE_TITLE
		);
	}
}

//===========================================
// 描画処理
//===========================================
void CResult::Draw()
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
CResult* CResult::Create(MODE mode)
{
	// 生成する
	CResult* pResult = new CResult;
	pResult->Init();

	return pResult;
}