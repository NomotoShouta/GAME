//==============================
//
// �v���C���[����[Player.cpp]
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

// �ÓI�����o������
Player* Player::m_aPlayer = 0;

//===========================================
// �R���X�g���N�^
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
// �f�X�g���N�^
//===========================================
Player::~Player()
{

}

//===========================================
// �����ݒ�
//===========================================
HRESULT Player::Init()
{
	m_Keyboard = CManager::GetKeyboard();
	m_Camera = CManager::GetCamera();

	// �f�o�C�X�̃|�C���^
	CRenderer* pRenderer = CManager::GetRenderer();			
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();		

	// �|���S���̏��̏�����
	m_pos = D3DXVECTOR3(-180.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, -3.14f / 2, 0.0f);
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	 

	//X�t�@�C���̓ǂݍ���
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
// �I������
//===========================================
void Player::Uninit()
{
	// �e�N�X�`���̔j��
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}

	// ���_�o�b�t�@�̔j��
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}

	CObject::Release();
}

//===========================================d
// �X�V����
//===========================================
void Player::Update()
{
	if (m_Keyboard->GetPress(DIK_A) == true)
	{
		if (m_Keyboard->GetPress(DIK_W) == true)
		{
			// ����ړ�
			m_pos.x = m_pos.x -= sinf(3.14f) * 2.0f;
			m_pos.z = m_pos.z -= cosf(3.14f) * 2.0f;
		}

		m_pos.x -= 4.0f;
	}
	if (m_Keyboard->GetPress(DIK_S) == true)
	{
		if (m_Keyboard->GetPress(DIK_D) == true)
		{
			// �E��ړ�
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
			// �E���ړ�
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
			// �����ړ�
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
// �`�揈��
//===========================================
void Player::Draw()
{
	//�f�o�C�X���擾����
	CRenderer* pRenderer = CManager::GetRenderer();			
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();		

	D3DXMATRIX mtxRot, mtxTrans;   
	D3DMATERIAL9 matDef;
	pDevice->GetMaterial(&matDef);

	D3DXMATRIX mtxView;

	// �A���t�@�e�X�g��L��
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	//���[���h�}�g���b�N�X������������
	D3DXMatrixIdentity(&m_mtxWorld);

	// �r���[�}�g���b�N�X���擾
	pDevice->GetTransform(D3DTS_VIEW, &mtxView);

	// �����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);

	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	// �ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);

	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	// ���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	D3DXMATERIAL* pMat;

	// �}�e���A���f�[�^�ւ̃|�C���^���擾
	pMat = (D3DXMATERIAL*)m_pBuffMat->GetBufferPointer();

	// ���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));

	// ���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_3D);

	for (int nCntMat = 0; nCntMat < (int)m_dwNumMat; nCntMat++)
	{
		// �}�e���A���̐ݒ�
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		// �e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, m_pTexture);

		// �|���S���̕`��
		m_pMesh->DrawSubset(nCntMat);

	}
	// �ۑ����Ă����}�e���A����߂�
	pDevice->SetMaterial(&matDef);

	// �A���t�@�e�X�g�𖳌��ɂ���
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
}

//===========================================
// Object3D�̎擾
//===========================================
Player* Player::GetPlayer()
{
	return &m_aPlayer[0];
}

//===========================================
// Object3D����
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
// �ʒu���ȂǗp��
//===========================================
D3DXVECTOR3* Player::GetPos()
{
	return &m_pos;
}