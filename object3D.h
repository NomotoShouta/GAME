//==============================
//
// オブジェクト3D処理[object3D.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _OBJECT3D_H_// このマクロ定義がされてなかったら
#define _OBJECT3D_H_// ２重インクルード防止のマクロ定義

#include "main.h"
#include "object.h"
#include "renderer.h"

// オブジェクト3Dクラス
class CObject3D : public CObject
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

	CObject3D();					// コンストラクタ
	~CObject3D() override;			// デストラクタ

	HRESULT Init()override;			// 初期化処理
	void Uninit() override;			// 終了処理
	void Update() override;			// 更新処理
	void Draw() override;			// 描画処理
	void BindTexture(LPDIRECT3DTEXTURE9 pTex);
	D3DXVECTOR3& GetPos() { return m_pos; }
	static CObject3D* Create();		
	static HRESULT Load();			
	static void Unload();			
	static CObject3D* GetObject3D();


protected:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;  

	// テクスチャとか
	LPDIRECT3DTEXTURE9 m_pTexture;		
	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_rot;

	static CObject3D* m_aObject3D;		
	D3DXMATRIX m_mtxWorld;
};

#endif

