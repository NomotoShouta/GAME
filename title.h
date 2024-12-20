//==============================
//
// タイトル処理[title.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _TITLE_H_ // このマクロ定義がされてなかったら
#define _TITLE_H_// ２重インクルード防止のマクロ定義

#include "main.h"
#include "renderer.h"
#include "scene.h"
#include "keyboard.h"

class CTitle :public CScene
{
public:

	CTitle();
	~CTitle()override;
	HRESULT Init()override;	// 初期化処理
	void Uninit()override;	// 終了処理
	void Update()override;	// 更新処理
	void Draw()override;	// 描画処理
	static CTitle* Create(MODE mode);

private:
	MODE m_Mode;
	CInputKeyboard* m_Keyboard;
	/*CObject2D* pBg;*/
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;   
	LPDIRECT3DTEXTURE9 m_pTexture;		 
};

#endif