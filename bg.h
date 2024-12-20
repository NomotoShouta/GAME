//==============================
//
// バックグラウンド処理[bg.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _BG_H_
#define _BG_H_

#include "main.h"
#include "object2D.h"

// マクロ定義
#define BGVTX_L		(0.0f)
#define BGVTX_R		(1280.0f)
#define BGVTX_U		(0.0f)
#define BGVTX_V		(720.0f)

class CBg : public CObject2D
{
public:

	CBg();
	~CBg()override;

	HRESULT Init()override;	// 初期化処理
	void Uninit() override;	// 終了処理
	void Update() override;	// 更新処理
	void Draw() override;	// 描画処理
	static CBg* Create();

};

#endif
