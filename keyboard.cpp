//==============================
//
// キーボード処理[keyboard.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "keyboard.h"

//===========================================
// コンストラクタ
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
// デストラクタ
//===========================================
CInputKeyboard::~CInputKeyboard()
{

}

//===========================================
// 初期設定
//===========================================
HRESULT CInputKeyboard::Init(HINSTANCE hInstance, HWND hWnd)
{
	if (FAILED(CInput::Init(hInstance, hWnd)))
	{
		return E_FAIL;
	}

	//キーボードの生成
	if (FAILED(m_pInput->CreateDevice(GUID_SysKeyboard, &m_pDevice, NULL)))
	{
		return E_FAIL;
	}

	//データフォーマットを設定
	if (FAILED(m_pDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}

	//協調モードを設定
	if (FAILED(m_pDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	//キーボードへのアクセス権を獲得
	m_pDevice->Acquire();

	return S_OK;
}

//===========================================
// 破棄
//===========================================
void CInputKeyboard::Uninit()
{
	// 入力デバイスを破棄する
	CInput::Uninit();
}

//===========================================
// 更新
//===========================================
void CInputKeyboard::Update()
{
	BYTE aKeyState[MAX_KEY];

	//入力デバイスからデータを取得
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
// 各種入力状態の関数
//===========================================
bool CInputKeyboard::GetPress(int nKey)
{
	return(m_aKeyState[nKey] & 0x80) != 0;
}

//===========================================
// トリガー情報の取得
//===========================================
bool CInputKeyboard::GetTrigger(int nKey)
{
	return(m_aKeyStateTrigger[nKey] & 0x80) != 0;
}