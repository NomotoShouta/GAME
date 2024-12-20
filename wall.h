//==============================
//
// 壁処理[wall.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _WALL_H_// このマクロ定義がされてなかったら
#define _WALL_H_// ２重インクルード防止のマクロ定義

#include "main.h"
#include "object.h"
#include "renderer.h"

// オブジェクト3Dクラス
class CWall : public CObject
{
public:
	// 頂点情報の構造体を定義
	typedef struct
	{
		D3DXVECTOR3 pos;	
		D3DXVECTOR3 nor;	
		D3DCOLOR col;		
		D3DXVECTOR2 tex;	
	}VERTEX_3D;

	typedef struct
	{
		D3DXVECTOR3 pos;	
		float rhw;			
		D3DCOLOR col;		
		D3DXVECTOR2 tex;	
	}VERTEX_2D;

	CWall();					// コンストラクタ
	~CWall() override;			// デストラクタ

	HRESULT Init()override;		// 初期化処理
	void Uninit() override;		// 終了処理
	void Update() override;		// 更新処理
	void Draw() override;		// 描画処理
	static CWall* Create();		
	static HRESULT Load();			
	static void Unload();			
	static CWall* GetWall();

protected:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff; 

	LPDIRECT3DTEXTURE9 m_pTexture;		
	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_rot;

	static CWall* m_aWall;		
	D3DXMATRIX m_mtxWorld;
};

#endif
