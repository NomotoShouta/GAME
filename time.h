//==============================
//
// タイム処理[time.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _TIME_H_// このマクロ定義がされてなかったら
#define _TIME_H_// ２重インクルード防止のマクロ定義

#include "main.h"
#include "object2D.h"

// マクロ定義
#define MAX_TIME (256)
#define MAX_DIGIT	(2)
#define START_TIME_POS	(600.0f)
#define START_NUMBER	(0.0f)
#define TIME_RIMIT (60)

// オブジェクト3Dクラス
class CTime : public CObject2D
{
public:
	typedef struct
	{
		D3DXVECTOR3 pos;
		bool bUse;
	}Time;

	CTime();
	~CTime()override;

	HRESULT Init()override;	// 初期化処理
	void Uninit() override;	// 終了処理
	void Update() override;	// 更新処理
	void Draw() override;	// 描画処理
	static CTime* Create();
	static CTime* GetObject2D();

	void SetTimePos(D3DXVECTOR3 pos, D3DXVECTOR2 tex);
	void SetTime(void);
	int GetTime(void);

private:
	static CTime* m_apTime;

	// グローバル変数
	LPDIRECT3DTEXTURE9 m_pTextureTime = NULL;
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffTime = NULL;
	Time m_aTime[MAX_TIME];
	float m_fTimeX;
	int m_nFrame = 0;
	int m_nTime = TIME_RIMIT;
};

#endif