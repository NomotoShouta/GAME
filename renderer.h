//==============================
//
// レンダラー処理[renderer.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _RENDERER_H_ // このマクロ定義がされてなかったら
#define _RENDERER_H_// ２重インクルード防止のマクロ定義

#include <Windows.h>
#include "d3dx9.h"
#include "main.h"

// レンダラークラス
class CRenderer
{
public:
	CRenderer();// コンストラクタ
	~CRenderer();// デストラクタ

	HRESULT Init(HWND hWnd, BOOL bWindow);
	void Uninit();// 終了処理
	void Update();// 更新処理
	void Draw();// 描画処理
	LPDIRECT3DDEVICE9 GetDevice();

private:
	LPDIRECT3D9 m_pD3D;						
	LPDIRECT3DDEVICE9 m_pD3DDevice;			
};

#endif
