//==============================
//
// シーン処理[scene.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _SCENE_H_ // このマクロ定義がされてなかったら
#define _SCENE_H_// ２重インクルード防止のマクロ定義

#include "main.h"
#include "renderer.h"
#include "object2D.h"
#include "keyboard.h"

// マネージャークラス
class CScene
{
public:

	// 画面の種類
	typedef enum
	{
		MODE_TITLE = 0,
		MODE_TUTORIAL,
		MODE_GAME,
		MODE_RESULT,
		MODE_MAX
	}MODE;

	CScene();				// コンストラクタ
	virtual ~CScene();		// デストラクタ
	virtual HRESULT Init();	// 初期化処理
	virtual void Uninit();	// 終了処理
	virtual void Update();	// 更新処理
	virtual void Draw();	// 描画処理
	static CScene* Create(MODE mode);

private:
	MODE m_Mode;
	CInputKeyboard* m_Keyboard;
};

#endif

