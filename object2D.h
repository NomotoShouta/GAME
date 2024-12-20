//==============================
//
// オブジェクト2D処理[object2D.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _OBJECT2D_H_// このマクロ定義がされてなかったら
#define _OBJECT2D_H_// ２重インクルード防止のマクロ定義

#include "main.h"
#include "object.h"

// マクロ定義
#define VTX_L		(600.0f)
#define VTX_R		(800.0f)
#define VTX_U		(350.0f)
#define VTX_V		(550.0f)
#define nANIMATION	(5)

// オブジェクト2Dクラス
class CObject2D : public CObject
{
public:
	typedef struct
	{
		D3DXVECTOR3 pos;	
		float rhw;			
		D3DCOLOR col;		
		D3DXVECTOR2 tex;	
	}VERTEX_2D;

	CObject2D();			 // コンストラクタ
	~CObject2D() override;   // デストラクタ

	HRESULT Init()override;	// 初期化処理
	void Uninit() override;	// 終了処理
	void Update() override;	// 更新処理
	void Draw() override;	// 描画処理
	static CObject2D* Create();
	static CObject2D* GetObject2D();

	void BindTexture(LPDIRECT3DTEXTURE9 pTex);
	void SetPos(D3DXVECTOR3 pos);
	D3DXVECTOR3* GetPos();

protected:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;   

	// テクスチャとか
	LPDIRECT3DTEXTURE9 m_pTexture;		 
	static CObject2D* m_aObject2D;		
	int m_nCounterAnimPlayer;			
	int m_nPatternAnimPlayer;			
	float m_moveLObject = 0.0f;
	float m_moveRObject = 0.125f;
	float m_moveAdd = 0.125f;
	int m_animation = 0;
	VERTEX_2D m_Vertex[4];			

	D3DXVECTOR3 m_pos;				
	D3DXVECTOR3 m_move;				
	int m_nLife;				
};

#endif
