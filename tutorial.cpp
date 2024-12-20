//==============================
//
// �`���[�g���A������[tutorial.cpp]
// Author:Nomoto Shouta
//
//==============================

#include "tutorial.h"
#include "object.h"
#include "object2D.h"
#include "renderer.h"
#include "manager.h"
#include "keyboard.h"
#include "input.h"
#include "texture.h"

//===========================================
// �R���X�g���N�^
//===========================================
CTutorial::CTutorial()
{

}

//===========================================
// �f�X�g���N�^
//===========================================
CTutorial::~CTutorial()
{

}

//===========================================
// �����ݒ�
//===========================================
HRESULT CTutorial::Init()
{
	

	LPDIRECT3DDEVICE9 pDevice;

	CRenderer* pRenderer = CManager::GetRenderer();

	//�f�o�C�X�̎擾
	pDevice = pRenderer->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\�`���[�g���A��.png",
		&m_pTexture);

	CBg_re::Create();

	return S_OK;
}

//===========================================
// �I������
//===========================================
void CTutorial::Uninit()
{
	CScene::Uninit();
}

//===========================================
// �X�V����
//===========================================
void CTutorial::Update()
{
	if (m_Keyboard->GetTrigger(DIK_SPACE) == true)
	{
		CManager::SetScene(CScene::MODE_TITLE);
	}
}

//===========================================
// �`�揈��
//===========================================
void CTutorial::Draw()
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
CTutorial* CTutorial::Create(MODE mode)
{
	// ��������
	CTutorial* pResult = new CTutorial;
	pResult->Init();

	return pResult;
}