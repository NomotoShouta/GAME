//==============================
//
// メイン処理[main.h]
// Author:Nomoto Shouta
//
//==============================

#ifndef _MAIN_H_ // このマクロ定義がされてなかったら
#define _MAIN_H_// ２重インクルード防止のマクロ定義

// インクルード
#include <windows.h>
#include "d3dx9.h"// 描画処理に必要

#define DIRECTINPUT_VERSION (0x0800)// ビルド時の警戒対処用マクロ
#include "dinput.h"// 入力処理に必要
#include "xaudio2.h"
#include "Xinput.h"

// ライブラリのリンク
#pragma comment(lib,"d3d9.lib")		// 描画処理に必要
#pragma comment(lib,"d3dx9.lib")	// [d3d9.lib]の拡張ライブラリ
#pragma comment(lib,"dxguid.lib")	// DirectXコンポーネント（部品）仕様に必要
#pragma comment (lib, "winmm.lib")	// システム時刻取得に必要
#pragma comment(lib, "dinput8.lib") // 入力処理に必要
#pragma comment(lib,"xinput.lib")//ジョイパット処理

// マクロ定義
#define CLASS_NAME		("WindowsClass")
#define WINDOW_NAME		("ゲーム")
#define SCREEN_WIDTH	(1280)	// ウインドウの幅
#define SCREEN_HEIGHT	(720)	// ウインドウの高さ
#define FVF_VERTEX_2D	(D3DFVF_XYZRHW |D3DFVF_DIFFUSE |D3DFVF_TEX1)
#define FVF_VERTEX_3D (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1)


// 頂点情報の構造体を定義
typedef struct
{
	D3DXVECTOR3 pos;	// 頂点座標
	float rhw;			// 座標変換用係数
	D3DCOLOR col;		// 頂点カラー
	D3DXVECTOR2 tex;	// テクスチャ座標
}VERTEX_2D;

// プロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#endif
