//==============================
//
// オブジェクト3D処理[object3D.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "object3D.h"
#include "object.h"
#include "renderer.h"
#include "main.h"
#include "manager.h"

// 静的メンバ初期化
CObject3D* CObject3D::m_aObject3D = 0;

//===========================================
// コンストラクタ
//===========================================
CObject3D::CObject3D()
{
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;
	D3DXMatrixIdentity(&m_mtxWorld);
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

//===========================================
// デストラクタ
//===========================================
CObject3D::~CObject3D()
{

}

//===========================================
// 初期設定
//===========================================
HRESULT CObject3D::Init()
{
	// デバイスのポインタ
	CRenderer* pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	// テクスチャの読み込み(テクスチャのデータを生成してる)
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\ステージ.png", &m_pTexture);

	// ポリゴンの情報の初期化
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// 頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4,
		D3DUSAGE_WRITEONLY, FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_3D* pVtx;

	// 頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// 頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(-750.0f, 0.0f, +650.0f);
	pVtx[1].pos = D3DXVECTOR3(+750.0f, 0.0f, +650.0f);
	pVtx[2].pos = D3DXVECTOR3(-750.0f, 0.0f, -650.0f);
	pVtx[3].pos = D3DXVECTOR3(+750.0f, 0.0f, -650.0f);

	// 法線ベクトルの設定
	pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	pVtx += 4;

	m_pVtxBuff->Unlock();

	return S_OK;
}

//===========================================
// 終了処理
//===========================================
void CObject3D::Uninit()
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
void CObject3D::Update()
{

}

//===========================================
// 描画処理
//===========================================
void CObject3D::Draw()
{
	//デバイスを取得する
	CRenderer* pRenderer = CManager::GetRenderer();			
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();		

	D3DXMATRIX mtxRot, mtxTrans;   

	//ワールドマトリックスを初期化する
	D3DXMatrixIdentity(&m_mtxWorld);

	// 向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);

	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	// 位置を反映
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);

	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	// ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	// 頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));

	// 頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_3D);

	// テクスチャの設定
	pDevice->SetTexture(0, m_pTexture);

	// ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

//===========================================
// テクスチャ設定
//===========================================
void CObject3D::BindTexture(LPDIRECT3DTEXTURE9 pTex)
{
	m_pTexture = pTex;
}

//===========================================
// Object3Dの取得
//===========================================
CObject3D* CObject3D::GetObject3D()
{
	return &m_aObject3D[0];
}

//===========================================
// Object3D生成
//===========================================
CObject3D* CObject3D::Create()
{
	if (m_aObject3D == nullptr)
	{
		m_aObject3D = new CObject3D;
		m_aObject3D->Init();
	}
	return  m_aObject3D;
}