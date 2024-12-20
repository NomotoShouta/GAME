//==============================
//
// リザルト処理[result.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _RESULT_H_ // このマクロ定義がされてなかったら
#define _RESULT_H_// ２重インクルード防止のマクロ定義

#include "main.h"
#include "renderer.h"
#include "scene.h"
#include "keyboard.h"

class CResult :public CScene
{
public:

	CResult();
	~CResult()override;
	HRESULT Init()override;	// 初期化処理
	void Uninit()override;	// 終了処理
	void Update()override;	// 更新処理
	void Draw()override;	// 描画処理
	static CResult* Create(MODE mode);

private:
	MODE m_Mode;// 現在のモード
	CInputKeyboard* m_Keyboard;

	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;  
	LPDIRECT3DTEXTURE9 m_pTexture;		
};

#endif
