//==============================
//
// 敵１処理[enemy.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "enemy.h"
#include "renderer.h"
#include "main.h"
#include "manager.h"
#include "object3D.h"

// 静的メンバ初期化
enemy* enemy::m_aEnemy[MAX_ENEMY] = {};

//===========================================
// コンストラクタ
//===========================================
enemy::enemy()
{
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;
	D3DXMatrixIdentity(&m_mtxWorld);   
	m_Epos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);  
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);   
	m_nELife = 3;
}

//===========================================
// デストラクタ
//===========================================
enemy::~enemy()
{

}

//===========================================
// 初期設定
//===========================================
HRESULT enemy::Init()
{
	// デバイスのポインタ
	CRenderer* pRenderer = CManager::GetRenderer();			
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();		

	// ポリゴンの情報の初期化
	m_Epos = D3DXVECTOR3(300.0f, 100.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 8.00f, 0.0f);

	// オブジェクト取得
	CObject::SetType(ENEMY);

	//Xファイルの読み込み
	D3DXLoadMeshFromX("data\\MODEL\\enemy_01.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&m_pBuffMat,
		NULL,
		&m_dwNumMat,
		&m_pMesh);

	return S_OK;
}

//===========================================
// 終了処理
//===========================================
void enemy::Uninit()
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

	CObject::Release();
}

//===========================================
// 更新処理
//===========================================
void enemy::Update()
{
	m_Epos.x -= 1.5f;

	if (m_Epos.x + 20.0f / 2 <= -200.0f)
	{
		m_Epos.x = 470.0f;
	}

}

//===========================================
// 描画処理
//===========================================
void enemy::Draw()
{
	//デバイスを取得する
	CRenderer* pRenderer = CManager::GetRenderer();			
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();		

	D3DXMATRIX mtxRot, mtxTrans;   
	D3DMATERIAL9 matDef;
	pDevice->GetMaterial(&matDef);

	D3DXMATRIX mtxView;

	// アルファテストを有効
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	//ワールドマトリックスを初期化する
	D3DXMatrixIdentity(&m_mtxWorld);

	// ビューマトリックスを取得
	pDevice->GetTransform(D3DTS_VIEW, &mtxView);

	// 向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);

	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	// 位置を反映
	D3DXMatrixTranslation(&mtxTrans, m_Epos.x, m_Epos.y, m_Epos.z);

	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	// ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	D3DXMATERIAL* pMat;


	// マテリアルデータへのポインタを取得
	pMat = (D3DXMATERIAL*)m_pBuffMat->GetBufferPointer();

	// 頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));

	// 頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_3D);

	for (int nCntMat = 0; nCntMat < (int)m_dwNumMat; nCntMat++)
	{
		// マテリアルの設定
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		// テクスチャの設定
		pDevice->SetTexture(0, m_pTexture);

		// ポリゴンの描画
		m_pMesh->DrawSubset(nCntMat);

	}
	// 保存していたマテリアルを戻す
	pDevice->SetMaterial(&matDef);

	// アルファテストを無効にする
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
}

//===========================================
// Object3Dの取得
//===========================================
enemy* enemy::Getenemy()
{
	return 0;
}

//===========================================
// Object3D生成
//===========================================
enemy* enemy::Create(D3DXVECTOR3 pos)
{
	m_aEnemy[MAX_ENEMY] = new enemy;
	m_aEnemy[MAX_ENEMY]->Init();

	return  m_aEnemy[MAX_ENEMY];
}

void enemy::EnemyCreater()
{
	if ((rand() % 100) == 0)
	{
		//敵生成
		enemy::Create(D3DXVECTOR3(0.0f, 80.0f, 0.0f));
	}
}

//===========================================
// 位置情報など用意
//===========================================
D3DXVECTOR3* enemy::GetPos()
{
	return &m_Epos;
}

void enemy::Damage(int nDamage)
{
	m_nELife -= nDamage;

	if (m_nELife <= 0)
	{
		Release();
	}

}