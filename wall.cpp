//==============================
//
// �Ǐ���[wall.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "wall.h"
#include "object.h"
#include "renderer.h"
#include "main.h"
#include "manager.h"

// �ÓI�����o������
CWall* CWall::m_aWall = 0;

//===========================================
// �R���X�g���N�^
//===========================================
CWall::CWall()
{
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;
	D3DXMatrixIdentity(&m_mtxWorld);   
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);   
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);   
}

//===========================================
// �f�X�g���N�^
//===========================================
CWall::~CWall()
{

}

//===========================================
// �����ݒ�
//===========================================
HRESULT CWall::Init()
{
	// �f�o�C�X�̃|�C���^
	CRenderer* pRenderer = CManager::GetRenderer();			
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();		

	// �e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\yuka.jpeg", &m_pTexture);

	// �|���S���̏��̏�����
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 15.0f);
	m_rot = D3DXVECTOR3(-3.14f / 2, 0.0f, 0.0f);

	// ���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4,
		D3DUSAGE_WRITEONLY, FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_3D* pVtx;

	// ���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// ���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(-750.0f, 0.0f, +250.0f);
	pVtx[1].pos = D3DXVECTOR3(+750.0f, 0.0f, +250.0f);
	pVtx[2].pos = D3DXVECTOR3(-750.0f, 0.0f, -250.0f);
	pVtx[3].pos = D3DXVECTOR3(+750.0f, 0.0f, -250.0f);

	// �@���x�N�g���̐ݒ�
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
// �I������
//===========================================
void CWall::Uninit()
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
}

//===========================================
// �X�V����
//===========================================
void CWall::Update()
{

}

//===========================================
// �`�揈��
//===========================================
void CWall::Draw()
{
	////�f�o�C�X���擾����
	//CRenderer* pRenderer = CManager::GetRenderer();			
	//LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();		

	//D3DXMATRIX mtxRot, mtxTrans;   

	////���[���h�}�g���b�N�X������������
	//D3DXMatrixIdentity(&m_mtxWorld);

	//// �����𔽉f
	//D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);

	//D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	//// �ʒu�𔽉f
	//D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);

	//D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	//// ���[���h�}�g���b�N�X�̐ݒ�
	//pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	//// ���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	//pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));

	//// ���_�t�H�[�}�b�g�̐ݒ�
	//pDevice->SetFVF(FVF_VERTEX_3D);

	//// �e�N�X�`���̐ݒ�
	//pDevice->SetTexture(0, m_pTexture);

	//// �|���S���̕`��
	//pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

//===========================================
// Wall�̎擾
//===========================================
CWall* CWall::GetWall()
{
	return &m_aWall[0];
}

//===========================================
// Wall����
//===========================================
CWall* CWall::Create()
{
	if (m_aWall == nullptr)
	{
		m_aWall = new CWall;
		m_aWall->Init();
	}
	return  m_aWall;
}