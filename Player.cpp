//==============================
//
// プレイヤー処理[Player.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "main.h"
#include "manager.h"
#include "Player.h"
#include "object3D.h"
#include "renderer.h"
#include "keyboard.h"
#include "input.h"
#include "camera.h"
#include "enemy.h"

// 静的メンバ初期化
Player* Player::m_aPlayer = 0;

//===========================================
// コンストラクタ
//===========================================
Player::Player()
{
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;
	D3DXMatrixIdentity(&m_mtxWorld);   
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);   
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);   
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	
	m_nCntCooltime = 0;
	m_nCntCooltimeMR = 0;
	m_nCntCooltimeSP = 0;
}

//===========================================
// デストラクタ
//===========================================
Player::~Player()
{

}

//===========================================
// 初期設定
//===========================================
HRESULT Player::Init()
{
	m_Keyboard = CManager::GetKeyboard();
	m_Camera = CManager::GetCamera();

	// デバイスのポインタ
	CRenderer* pRenderer = CManager::GetRenderer();			
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();		

	// ポリゴンの情報の初期化
	m_pos = D3DXVECTOR3(-180.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, -3.14f / 2, 0.0f);
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	 

	//Xファイルの読み込み
	D3DXLoadMeshFromX("data\\MODEL\\Bee.x",
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
void Player::Uninit()
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

//===========================================d
// 更新処理
//===========================================
void Player::Update()
{
	if (m_Keyboard->GetPress(DIK_A) == true)
	{
		if (m_Keyboard->GetPress(DIK_W) == true)
		{
			// 左上移動
			m_pos.x = m_pos.x -= sinf(3.14f) * 2.0f;
			m_pos.z = m_pos.z -= cosf(3.14f) * 2.0f;
		}

		m_pos.x -= 4.0f;
	}
	if (m_Keyboard->GetPress(DIK_S) == true)
	{
		if (m_Keyboard->GetPress(DIK_D) == true)
		{
			// 右上移動
			m_pos.x = m_pos.x += sinf(3.14f) * 2.0f;
			m_pos.z = m_pos.z -= cosf(3.14f) * 2.0f;
		}
		// S
		m_pos.z -= 4.0f;
	}
	if (m_Keyboard->GetPress(DIK_D) == true)
	{
		if (m_Keyboard->GetPress(DIK_S) == true)
		{
			// 右下移動
			m_pos.x = m_pos.x += sinf(3.14f) * 2.0f;
			m_pos.z = m_pos.z += cosf(3.14f) * 2.0f;
		}
		// D
		m_pos.x += 4.0f;
	}
	if (m_Keyboard->GetPress(DIK_W) == true)
	{
		if (m_Keyboard->GetPress(DIK_A) == true)
		{
			// 左下移動
			m_pos.x = m_pos.x -= sinf(3.14f) * 2.0f;
			m_pos.z = m_pos.z += cosf(3.14f) * 2.0f;
		}
		// W
		m_pos.z += 4.0f;
	}

	m_nCntCooltime--;

	if (m_Keyboard->GetTrigger(DIK_SPACE) == true)
	{
		
		m_move.y = 15.0f;
	}
	m_move.y += -1.0f;

	m_pos.z += m_move.z;
	m_pos.x += m_move.x;
	m_pos.y += m_move.y;

	m_move.x += (0.0f - m_move.x) * 0.1;

	if (m_pos.y <= 0.0f &&
		m_posOld.y >= 0.0f)
	{
		m_pos.y = 0.0f;

		m_move.y = 0.0f;
	}
	
	if (m_pos.x + 20.0f / 2 <= -360.0f)
	{
		m_pos.x = -370.0f;
	}
	else if (m_pos.x + 10.0f / 2 >= 380.0f)
	{
		m_pos.x = 375.0f;
	}

	if (m_pos.y + 335.0f / 2 <= 0.0f)
	{
		m_pos.y = 340.0f - 335.0f / 2;
	}
	else if (m_pos.y + 335.0f / 2 >= 340.0f)
	{
		m_pos.y = 0.0f + 335.0f / 2;
	}

	for (int nCntObj = 0; nCntObj < MAX_ENEMY; nCntObj++)
	{
		CObject* pObj = CObject::GetObject(nCntObj);
		if (pObj != nullptr)
		{
			
			CObject::TYPE type = pObj->GetType();
			if (type == CObject::TYPE::ENEMY)
			{
				enemy* pEnemy = (enemy*)pObj;
				pEnemy->GetPos();
				if (m_pos.x >= pEnemy->m_Epos.x - 50
					&& m_pos.x <= pEnemy->m_Epos.x + 50
					&& m_pos.y >= pEnemy->m_Epos.y - 50
					&& m_pos.y <= pEnemy->m_Epos.y + 50)
				{
					pEnemy->Damage(1);

					pEnemy->Uninit();

					Uninit();

					CManager::SetScene(CScene::MODE_RESULT);

					return;

				}
			}
		}
	}
}

//===========================================
// 描画処理
//===========================================
void Player::Draw()
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
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);

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
Player* Player::GetPlayer()
{
	return &m_aPlayer[0];
}

//===========================================
// Object3D生成
//===========================================
Player* Player::Create(D3DXVECTOR3 pos)
{
	if (m_aPlayer == nullptr)
	{
		m_aPlayer = new Player;
		m_aPlayer->Init();
	}
	return  m_aPlayer;
}

//===========================================
// 位置情報など用意
//===========================================
D3DXVECTOR3* Player::GetPos()
{
	return &m_pos;
}