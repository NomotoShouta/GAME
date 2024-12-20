//==============================
//
// チュートリアル処理[tutorial.h]
// Author:Nomoto Shouta
//
//==============================

#ifndef _TUTORIAL_H
#define _TUTORIAL_H

#include "main.h"
#include "renderer.h"
#include "scene.h"
#include "keyboard.h"

class CTutorial :public CScene
{
public:

	CTutorial();
	~CTutorial()override;
	HRESULT Init()override;	// 初期化処理
	void Uninit()override;	// 終了処理
	void Update()override;	// 更新処理
	void Draw()override;	// 描画処理
	static CTutorial* Create(MODE mode);

private:
	MODE m_Mode;// 現在のモード
	CInputKeyboard* m_Keyboard;
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;
	LPDIRECT3DTEXTURE9 m_pTexture;
};
#endif