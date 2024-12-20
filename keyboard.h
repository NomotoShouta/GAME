//==============================
//
// キーボード処理[keyboard.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <Windows.h>
#include "d3dx9.h"
#include "main.h"
#include "input.h"

// キーボード入力
class CInputKeyboard : public CInput
{
public:
	CInputKeyboard();
	~CInputKeyboard();
	HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	void Uninit();
	void Update();

	bool GetPress(int nKey);
	bool GetTrigger(int nKey);

private:
	BYTE m_aKeyState[MAX_KEY];
	BYTE m_aKeyStateTrigger[MAX_KEY];
	LPDIRECTINPUTDEVICE8 m_pDevKeyboard = NULL;		
};

#endif
