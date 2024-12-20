//==============================
//
// �^�C�g������[title.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "title.h"
#include "object.h"
#include "object2D.h"
#include "renderer.h"
#include "manager.h"
#include "keyboard.h"
#include "input.h"
#include "bg.h"

//===========================================
// �R���X�g���N�^
//===========================================
CTitle::CTitle()
{

}

//===========================================
// �f�X�g���N�^
//===========================================
CTitle::~CTitle()
{

}

//===========================================
// �����ݒ�
//===========================================
HRESULT CTitle::Init()
{
	m_Keyboard = CManager::GetKeyboard();

	LPDIRECT3DDEVICE9 pDevice;		

	CRenderer* pRenderer = CManager::GetRenderer();

	//�f�o�C�X�̎擾
	pDevice = pRenderer->GetDevice();

	////�e�N�X�`���̓ǂݍ���
	//D3DXCreateTextureFromFile(pDevice,
	//	"data\\TEXTURE\\bg000.jpg",
	//	&m_pTexture);

	CBg::Create();

	return S_OK;
}

//===========================================
//===========================================
// �I������
void CTitle::Uninit()
{
	CScene::Uninit();
}

//===========================================
// �X�V����
//===========================================
void CTitle::Update()
{
	if (m_Keyboard->GetTrigger(DIK_RETURN) == true)
	{
		CManager::SetScene(CScene::MODE_GAME);
	}
}

//===========================================
// �`�揈���i�����_���[�̕`��j
//===========================================
void CTitle::Draw()
{
	LPDIRECT3DDEVICE9 pDevice;		

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
// ��������
//===========================================
CTitle* CTitle::Create(MODE mode)
{
	CTitle* pTitle = new CTitle;
	pTitle->Init();

	return pTitle;
}