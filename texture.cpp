//==============================
//
// テクスチャ処理[bg_re.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "texture.h"
#include "manager.h"
#include "object2D.h"

float m_aPosTexV[1];

//===========================================
// コンストラクタ
//===========================================
CBg_re::CBg_re()
{
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;

}

//===========================================
// 
// デストラクタ
//===========================================
CBg_re::~CBg_re()
{

}

//===========================================
// 初期設定
//===========================================
HRESULT CBg_re::Init()
{
	int nCntBG;

	LPDIRECT3DDEVICE9 pDevice;//デバイスへのポインタ

	CRenderer* pRenderer = CManager::GetRenderer();

	//デバイスの取得
	pDevice = pRenderer->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\result.png",
		&m_pTexture);

	// テクスチャ座標の開始位置の初期化
	for (nCntBG = 0; nCntBG < 1; nCntBG++)
	{
		m_aPosTexV[nCntBG] = 0.0f;
	}

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_2D* pVtx;//頂点情報へのポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//頂点座標の指定
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(1280.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 730.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(1280.0f, 730.0f, 0.0f);

	//rhwの設定
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//頂点カラーの設定
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	//テクスチャ座標の設定
	pVtx[0].tex = D3DXVECTOR2(0.0f, m_aPosTexV[nCntBG]);
	pVtx[1].tex = D3DXVECTOR2(1.0f, m_aPosTexV[nCntBG]);
	pVtx[2].tex = D3DXVECTOR2(0.0f, m_aPosTexV[nCntBG] + 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, m_aPosTexV[nCntBG] + 1.0f);


	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();

	return S_OK;
}

//===========================================
// 終了処理
//===========================================
void CBg_re::Uninit()
{
	CObject2D::Uninit();
}

//===========================================
// 更新処理
//===========================================
void CBg_re::Update()
{
	int nCntBG = 0;

	VERTEX_2D* pVtx;// 頂点情報へのポインタ

	// 頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	m_aPosTexV[nCntBG] += 0.002f;


	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}

//===========================================
// 描画処理
//===========================================
void CBg_re::Draw()
{
	LPDIRECT3DDEVICE9 pDevice;//デバイスへのポインタ

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
// Object2D生成
//===========================================
CBg_re* CBg_re::Create()
{
	CBg_re* pBg = new CBg_re;
	pBg->Init();
	return pBg;
}