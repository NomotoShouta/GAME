//==============================
//
//	マネージャー処理[Manager.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _MANAGER_H_ // このマクロ定義がされてなかったら
#define _MANAGER_H_// ２重インクルード防止のマクロ定義

#include "main.h"
#include "renderer.h"
#include "keyboard.h"
#include "camera.h"
#include "light.h"
#include "scene.h"

class CRenderer;

// マネージャークラス
class CManager
{
public:
	CManager();
	~CManager();
	HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);	// 初期化処理
	void Uninit();												// 終了処理
	void Update();												// 更新処理
	void Draw();												// 描画処理
	static CRenderer* GetRenderer();
	static CInputKeyboard* GetKeyboard();
	static CCamera* GetCamera();
	static CLight* GetLight();
	static void SetScene(CScene::MODE mode);

	static CManager* GetInstance()
	{
		static CManager instance;
		return &instance;
	}

private:
	static CRenderer* m_pRnderer;
	static CInputKeyboard* m_pKeyboard;
	static CCamera* m_pCamera;
	static CLight* m_pLight;
	static CScene* m_pScene;
};

#endif
