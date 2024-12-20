//==============================
//
// インプット処理[input.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _INPUT_H_ // このマクロ定義がされてなかったら
#define _INPUT_H_// ２重インクルード防止のマクロ定義

#include <Windows.h>
#include "d3dx9.h"
#include "main.h"

#define MAX_KEY	(256)

// レンダラークラス
class CInput
{
public:
	CInput();// コンストラクタ
	~CInput();// デストラクタ

	virtual HRESULT Init(HINSTANCE hInstance, HWND hWnd);// 初期化処理
	virtual void Uninit();// 終了処理
	virtual void Update() = 0;// 更新処理

protected:
	static LPDIRECTINPUT8 m_pInput;
	LPDIRECTINPUTDEVICE8 m_pDevice;
};
#endif
