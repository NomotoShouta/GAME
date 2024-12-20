//==============================
//
// �G�P����[enemy.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "enemy.h"
#include "renderer.h"
#include "main.h"
#include "manager.h"
#include "object3D.h"

// �ÓI�����o������
enemy* enemy::m_aEnemy[MAX_ENEMY] = {};

//===========================================
// �R���X�g���N�^
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
// �f�X�g���N�^
//===========================================
enemy::~enemy()
{

}

//===========================================
// �����ݒ�
//===========================================
HRESULT enemy::Init()
{
	// �f�o�C�X�̃|�C���^
	CRenderer* pRenderer = CManager::GetRenderer();			
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();		

	// �|���S���̏��̏�����
	m_Epos = D3DXVECTOR3(300.0f, 100.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 8.00f, 0.0f);

	// �I�u�W�F�N�g�擾
	CObject::SetType(ENEMY);

	//X�t�@�C���̓ǂݍ���
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
// �I������
//===========================================
void enemy::Uninit()
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

//===========================================
// �X�V����
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
// �`�揈��
//===========================================
void enemy::Draw()
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
	D3DXMatrixTranslation(&mtxTrans, m_Epos.x, m_Epos.y, m_Epos.z);

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
enemy* enemy::Getenemy()
{
	return 0;
}

//===========================================
// Object3D����
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
		//�G����
		enemy::Create(D3DXVECTOR3(0.0f, 80.0f, 0.0f));
	}
}

//===========================================
// �ʒu���ȂǗp��
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