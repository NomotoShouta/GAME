//==============================
//
// �C���v�b�g����[input.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "input.h"

XINPUT_STATE g_joyKeyState;

// �ÓI�����o������
LPDIRECTINPUT8 CInput::m_pInput = nullptr;

//===========================================
// �R���X�g���N�^
//===========================================
CInput::CInput()
{
	m_pDevice = nullptr;
}

//===========================================
// �f�X�g���N�^
//===========================================
CInput::~CInput()
{

}

//===========================================
// ����������
//===========================================
HRESULT CInput::Init(HINSTANCE hInstance, HWND hWnd)
{
	if (m_pInput == nullptr)
	{
		if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pInput, NULL)))
		{
			return E_FAIL;
		}
	}

	return S_OK;
}

//===========================================
// �j��
//===========================================
void CInput::Uninit()
{
	if (m_pDevice != NULL)
	{
		m_pDevice->Unacquire();
		m_pDevice->Release();
		m_pDevice = NULL;
	}

	if (m_pInput != NULL)
	{
		m_pInput->Release();
		m_pInput = NULL;
	}

	if (m_pInput != NULL)
	{
		m_pInput->Release();
		m_pInput = NULL;
	}
}