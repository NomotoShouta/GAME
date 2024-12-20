//==============================
//
// �I�u�W�F�N�g2D����[object2D.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "object2D.h"
#include "object.h"
#include "renderer.h"
#include "main.h"
#include "manager.h"

// �ÓI�����o������
CObject2D* CObject2D::m_aObject2D = 0;

//===========================================
// �R���X�g���N�^
//===========================================
CObject2D::CObject2D()
{
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;
}

//===========================================
// �f�X�g���N�^
//===========================================
CObject2D::~CObject2D()
{

}

//===========================================
// �����ݒ�
//===========================================
HRESULT CObject2D::Init()
{
	LPDIRECT3DDEVICE9 pDevice;		

	CRenderer* pRenderer = CManager::GetRenderer();

	//�f�o�C�X�̎擾
	pDevice = pRenderer->GetDevice();

	// �e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\runningman000.png", &m_pTexture);

	m_nCounterAnimPlayer = 0;
	m_nPatternAnimPlayer = 0;

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_2D* pVtx;

	// ���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// ���_���W�̎w��
	pVtx[0].pos = D3DXVECTOR3(VTX_L, VTX_U, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(VTX_R, VTX_U, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(VTX_L, VTX_V, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(VTX_R, VTX_V, 0.0f);

	// rhw�̐ݒ�
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	// ���_�J���[�̐ݒ�
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	// �e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(0.125f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(0.125f, 1.0f);

	// ���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

	return S_OK;
}

//===========================================
// �I������
//===========================================
void CObject2D::Uninit()
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
void CObject2D::Update()
{
	VERTEX_2D* pVtx;		

	// ���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// �e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(m_moveLObject, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(m_moveRObject, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(m_moveLObject, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(m_moveRObject, 1.0f);

	m_animation++;

	// �A�j���[�V����
	if (m_animation == nANIMATION)
	{
		m_moveLObject += m_moveAdd;
		m_moveRObject += m_moveAdd;
		m_animation = 0;
	}

	// ���_���W�̐ݒ肷��
	pVtx[0].pos = D3DXVECTOR3(VTX_L, VTX_U, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(VTX_R, VTX_U, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(VTX_L, VTX_V, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(VTX_R, VTX_V, 0.0f);

	// ���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//===========================================
// �`�揈��
//===========================================
void CObject2D::Draw()
{
	LPDIRECT3DDEVICE9 pDevice;		

	CRenderer* pRenderer = CManager::GetRenderer();

	// �f�o�C�X�̎擾
	pDevice = pRenderer->GetDevice();

	// ���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

	// ���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	// �e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, m_pTexture);

	// �|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

//===========================================
// Object2D�̎擾
//===========================================
CObject2D* CObject2D::GetObject2D()
{
	return &m_aObject2D[0];
}

//===========================================
// Object2D����
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
// �e�N�X�`���ݒ�
//===========================================
void CObject2D::BindTexture(LPDIRECT3DTEXTURE9 pTex)
{
	m_pTexture = pTex;
}

//===========================================
// �ʒu���ȂǗp��
//===========================================
void CObject2D::SetPos(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//===========================================
// �ʒu���ȂǗp��
//===========================================
D3DXVECTOR3* CObject2D::GetPos()
{
	return &m_pos;
}