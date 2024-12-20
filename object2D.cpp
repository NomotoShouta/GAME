//==============================
//
// オブジェクト2D処理[object2D.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "object2D.h"
#include "object.h"
#include "renderer.h"
#include "main.h"
#include "manager.h"

// 静的メンバ初期化
CObject2D* CObject2D::m_aObject2D = 0;

//===========================================
// コンストラクタ
//===========================================
CObject2D::CObject2D()
{
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;
}

//===========================================
// デストラクタ
//===========================================
CObject2D::~CObject2D()
{

}

//===========================================
// 初期設定
//===========================================
HRESULT CObject2D::Init()
{
	LPDIRECT3DDEVICE9 pDevice;		

	CRenderer* pRenderer = CManager::GetRenderer();

	//デバイスの取得
	pDevice = pRenderer->GetDevice();

	// テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\runningman000.png", &m_pTexture);

	m_nCounterAnimPlayer = 0;
	m_nPatternAnimPlayer = 0;

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_2D* pVtx;

	// 頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// 頂点座標の指定
	pVtx[0].pos = D3DXVECTOR3(VTX_L, VTX_U, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(VTX_R, VTX_U, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(VTX_L, VTX_V, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(VTX_R, VTX_V, 0.0f);

	// rhwの設定
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	// 頂点カラーの設定
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	// テクスチャ座標の設定
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(0.125f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(0.125f, 1.0f);

	// 頂点バッファをアンロックする
	m_pVtxBuff->Unlock();

	return S_OK;
}

//===========================================
// 終了処理
//===========================================
void CObject2D::Uninit()
{
	// テクスチャの破棄
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}

	// 頂点バッファの破壊
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}
}

//===========================================
// 更新処理
//===========================================
void CObject2D::Update()
{
	VERTEX_2D* pVtx;		

	// 頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// テクスチャ座標の設定
	pVtx[0].tex = D3DXVECTOR2(m_moveLObject, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(m_moveRObject, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(m_moveLObject, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(m_moveRObject, 1.0f);

	m_animation++;

	// アニメーション
	if (m_animation == nANIMATION)
	{
		m_moveLObject += m_moveAdd;
		m_moveRObject += m_moveAdd;
		m_animation = 0;
	}

	// 頂点座標の設定する
	pVtx[0].pos = D3DXVECTOR3(VTX_L, VTX_U, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(VTX_R, VTX_U, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(VTX_L, VTX_V, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(VTX_R, VTX_V, 0.0f);

	// 頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}

//===========================================
// 描画処理
//===========================================
void CObject2D::Draw()
{
	LPDIRECT3DDEVICE9 pDevice;		

	CRenderer* pRenderer = CManager::GetRenderer();

	// デバイスの取得
	pDevice = pRenderer->GetDevice();

	// 頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

	// 頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	// テクスチャの設定
	pDevice->SetTexture(0, m_pTexture);

	// ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

//===========================================
// Object2Dの取得
//===========================================
CObject2D* CObject2D::GetObject2D()
{
	return &m_aObject2D[0];
}

//===========================================
// Object2D生成
//===========================================
CObject2D* CObject2D::Create()
{
	if (m_aObject2D == nullptr)
	{
		m_aObject2D = new CObject2D;
		m_aObject2D->Init();
	}
	return  m_aObject2D;
}

//===========================================
// テクスチャ設定
//===========================================
void CObject2D::BindTexture(LPDIRECT3DTEXTURE9 pTex)
{
	m_pTexture = pTex;
}

//===========================================
// 位置情報など用意
//===========================================
void CObject2D::SetPos(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//===========================================
// 位置情報など用意
//===========================================
D3DXVECTOR3* CObject2D::GetPos()
{
	return &m_pos;
}