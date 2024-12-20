//==============================
//
// �I�u�W�F�N�g3D����[object3D.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "object3D.h"
#include "object.h"
#include "renderer.h"
#include "main.h"
#include "manager.h"

// �ÓI�����o������
CObject3D* CObject3D::m_aObject3D = 0;

//===========================================
// �R���X�g���N�^
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
// �f�X�g���N�^
//===========================================
CObject3D::~CObject3D()
{

}

//===========================================
// �����ݒ�
//===========================================
HRESULT CObject3D::Init()
{
	// �f�o�C�X�̃|�C���^
	CRenderer* pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	// �e�N�X�`���̓ǂݍ���(�e�N�X�`���̃f�[�^�𐶐����Ă�)
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\�X�e�[�W.png", &m_pTexture);

	// �|���S���̏��̏�����
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

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
	pVtx[0].pos = D3DXVECTOR3(-750.0f, 0.0f, +650.0f);
	pVtx[1].pos = D3DXVECTOR3(+750.0f, 0.0f, +650.0f);
	pVtx[2].pos = D3DXVECTOR3(-750.0f, 0.0f, -650.0f);
	pVtx[3].pos = D3DXVECTOR3(+750.0f, 0.0f, -650.0f);

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
void CObject3D::Uninit()
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
void CObject3D::Update()
{

}

//===========================================
// �`�揈��
//===========================================
void CObject3D::Draw()
{
	//�f�o�C�X���擾����
	CRenderer* pRenderer = CManager::GetRenderer();			
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();		

	D3DXMATRIX mtxRot, mtxTrans;   

	//���[���h�}�g���b�N�X������������
	D3DXMatrixIdentity(&m_mtxWorld);

	// �����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);

	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	// �ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);

	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	// ���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	// ���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));

	// ���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_3D);

	// �e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, m_pTexture);

	// �|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

//===========================================
// �e�N�X�`���ݒ�
//===========================================
void CObject3D::BindTexture(LPDIRECT3DTEXTURE9 pTex)
{
	m_pTexture = pTex;
}

//===========================================
// Object3D�̎擾
//===========================================
CObject3D* CObject3D::GetObject3D()
{
	return &m_aObject3D[0];
}

//===========================================
// Object3D����
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