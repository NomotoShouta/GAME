//==============================
//
// ライト処理[light.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _LIGHT_H_// このマクロ定義がされてなかったら
#define _LIGHT_H_// ２重インクルード防止のマクロ定義

#include "main.h"

// マクロ定義
#define MAX_LIGHT	(128)

// ライト
class CLight
{
public:
	typedef struct
	{
		D3DLIGHT9 light;	
		D3DXVECTOR3 vecDir;	
	}Light;

	const static int MAX = 8;   

	CLight();   //コンストラクタ
	~CLight();   //デストラクタ

	void Init();   //初期化処理
	void Uninit();   //終了処理
	void Update();   //更新処理

private:
	Light m_aLight[MAX_LIGHT];   

};
#endif
