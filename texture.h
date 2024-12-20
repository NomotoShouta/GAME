//==============================
//
// テクスチャ処理[bg_re.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef __BG_RE_H_
#define __BG_RE_H_

#include "main.h"
#include "object2D.h"

// マクロ定義
#define BG_RE_VTX_L		(0.0f)
#define BG_RE_VTX_R		(1280.0f)
#define BG_RE_VTX_U		(0.0f)
#define BG_RE_VTX_V		(720.0f)

class CBg_re : public CObject2D
{
public:

	CBg_re();
	~CBg_re()override;

	HRESULT Init()override;	// 初期化処理
	void Uninit() override;	// 終了処理
	void Update() override;	// 更新処理
	void Draw() override;	// 描画処理
	static CBg_re* Create();
};

#endif
