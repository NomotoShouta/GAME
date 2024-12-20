//==============================
//
// ゲーム処理[game.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _GAME_H_ // このマクロ定義がされてなかったら
#define _GAME_H_// ２重インクルード防止のマクロ定義

#include "main.h"
#include "renderer.h"
#include "scene.h"
#include "keyboard.h"

class CGame :public CScene
{
public:

	CGame();
	~CGame()override;
	HRESULT Init()override;	// 初期化処理
	void Uninit()override;	// 終了処理
	void Update()override;	// 更新処理
	void Draw()override;	// 描画処理
	static CGame* Create(MODE mode);

private:
	MODE m_Mode;
	CInputKeyboard* m_Keyboard;

};

#endif
