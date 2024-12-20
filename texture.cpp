//==============================
//
// �e�N�X�`������[bg_re.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "texture.h"
#include "manager.h"
#include "object2D.h"

float m_aPosTexV[1];

//===========================================
// �R���X�g���N�^
//===========================================
CBg_re::CBg_re()
{
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;

}

//===========================================
// 
// �f�X�g���N�^
//===========================================
CBg_re::~CBg_re()
{

}

//===========================================
// �����ݒ�
//===========================================
HRESULT CBg_re::Init()
{
	int nCntBG;

	LPDIRECT3DDEVICE9 pDevice;//�f�o�C�X�ւ̃|�C���^

	CRenderer* pRenderer = CManager::GetRenderer();

	//�f�o�C�X�̎擾
	pDevice = pRenderer->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\result.png",
		&m_pTexture);

	// �e�N�X�`�����W�̊J�n�ʒu�̏�����
	for (nCntBG = 0; nCntBG < 1; nCntBG++)
	{
		m_aPosTexV[nCntBG] = 0.0f;
	}

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_2D* pVtx;//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̎w��
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(1280.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 730.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(1280.0f, 730.0f, 0.0f);

	//rhw�̐ݒ�
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, m_aPosTexV[nCntBG]);
	pVtx[1].tex = D3DXVECTOR2(1.0f, m_aPosTexV[nCntBG]);
	pVtx[2].tex = D3DXVECTOR2(0.0f, m_aPosTexV[nCntBG] + 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, m_aPosTexV[nCntBG] + 1.0f);


	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

	return S_OK;
}

//===========================================
// �I������
//===========================================
void CBg_re::Uninit()
{
	CObject2D::Uninit();
}

//===========================================
// �X�V����
//===========================================
void CBg_re::Update()
{
	int nCntBG = 0;

	VERTEX_2D* pVtx;// ���_���ւ̃|�C���^

	// ���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	m_aPosTexV[nCntBG] += 0.002f;


	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//===========================================
// �`�揈��
//===========================================
void CBg_re::Draw()
{
	LPDIRECT3DDEVICE9 pDevice;//�f�o�C�X�ւ̃|�C���^

	CRenderer* pRenderer = CManager::GetRenderer();

	//�f�o�C�X�̎擾
	pDevice = pRenderer->GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, m_pTexture);

	//�|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

//===========================================
// Object2D����
//===========================================
CBg_re* CBg_re::Create()
{
	CBg_re* pBg = new CBg_re;
	pBg->Init();
	return pBg;
}