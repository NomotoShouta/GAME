//==============================
//
// タイトル処理[title.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "title.h"
#include "object.h"
#include "object2D.h"
#include "renderer.h"
#include "manager.h"
#include "keyboard.h"
#include "input.h"
#include "bg.h"

//===========================================
// コンストラクタ
//===========================================
CTitle::CTitle()
{

}

//===========================================
// デストラクタ
//===========================================
CTitle::~CTitle()
{

}

//===========================================
// 初期設定
//===========================================
HRESULT CTitle::Init()
{
	m_Keyboard = CManager::GetKeyboard();

	LPDIRECT3DDEVICE9 pDevice;		

	CRenderer* pRenderer = CManager::GetRenderer();

	//デバイスの取得
	pDevice = pRenderer->GetDevice();

	////テクスチャの読み込み
	//D3DXCreateTextureFromFile(pDevice,
	//	"data\\TEXTURE\\bg000.jpg",
	//	&m_pTexture);

	CBg::Create();

	return S_OK;
}

//===========================================
//===========================================
// 終了処理
void CTitle::Uninit()
{
	CScene::Uninit();
}

//===========================================
// 更新処理
//===========================================
void CTitle::Update()
{
	if (m_Keyboard->GetTrigger(DIK_RETURN) == true)
	{
		CManager::SetScene(CScene::MODE_GAME);
	}
}

//===========================================
// 描画処理（レンダラーの描画）
//===========================================
void CTitle::Draw()
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
CTitle* CTitle::Create(MODE mode)
{
	CTitle* pTitle = new CTitle;
	pTitle->Init();

	return pTitle;
}