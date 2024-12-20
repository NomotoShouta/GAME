//==============================
//
// �L�[�{�[�h����[keyboard.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "keyboard.h"

//===========================================
// �R���X�g���N�^
//===========================================
CInputKeyboard::CInputKeyboard()
{
	for (int nCount = 0; nCount < MAX_KEY; nCount++)
	{
		m_aKeyState[nCount] = {};  
		m_aKeyStateTrigger[nCount] = {};   
	}
}

//===========================================
// �f�X�g���N�^
//===========================================
CInputKeyboard::~CInputKeyboard()
{

}

//===========================================
// �����ݒ�
//===========================================
HRESULT CInputKeyboard::Init(HINSTANCE hInstance, HWND hWnd)
{
	if (FAILED(CInput::Init(hInstance, hWnd)))
	{
		return E_FAIL;
	}

	//�L�[�{�[�h�̐���
	if (FAILED(m_pInput->CreateDevice(GUID_SysKeyboard, &m_pDevice, NULL)))
	{
		return E_FAIL;
	}

	//�f�[�^�t�H�[�}�b�g��ݒ�
	if (FAILED(m_pDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}

	//�������[�h��ݒ�
	if (FAILED(m_pDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	//�L�[�{�[�h�ւ̃A�N�Z�X�����l��
	m_pDevice->Acquire();

	return S_OK;
}

//===========================================
// �j��
//===========================================
void CInputKeyboard::Uninit()
{
	// ���̓f�o�C�X��j������
	CInput::Uninit();
}

//===========================================
// �X�V
//===========================================
void CInputKeyboard::Update()
{
	BYTE aKeyState[MAX_KEY];

	//���̓f�o�C�X����f�[�^���擾
	if (SUCCEEDED(m_pDevice->GetDeviceState(sizeof(aKeyState), &aKeyState[0])))
	{
		for (int nCount = 0; nCount < MAX_KEY; nCount++)

		{
			m_aKeyStateTrigger[nCount] = (m_aKeyState[nCount] ^ aKeyState[nCount]) & aKeyState[nCount];
			m_aKeyState[nCount] = aKeyState[nCount];   
		}
	}
	else
	{
		m_pDevice->Acquire();
	}
}

//===========================================
// �e����͏�Ԃ̊֐�
//===========================================
bool CInputKeyboard::GetPress(int nKey)
{
	return(m_aKeyState[nKey] & 0x80) != 0;
}

//===========================================
// �g���K�[���̎擾
//===========================================
bool CInputKeyboard::GetTrigger(int nKey)
{
	return(m_aKeyStateTrigger[nKey] & 0x80) != 0;
}