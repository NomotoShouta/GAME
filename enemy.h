//==============================
//
// 敵１処理[enemy.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _ENEMY_H_// このマクロ定義がされてなかったら
#define _ENEMY_H_// ２重インクルード防止のマクロ定義

#include "main.h"
#include "object.h"
#include "renderer.h"
#include "manager.h"

// マクロ定義
#define MAX_ENEMY (200)

// オブジェクトXクラス
class enemy : public CObject
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

	enemy();				// コンストラクタ
	~enemy() override;		// デストラクタ

	HRESULT Init()override;			// 初期化処理
	void Uninit() override;			// 終了処理
	void Update() override;			// 更新処理
	void Draw() override;			// 描画処理
	static enemy* Create(D3DXVECTOR3 pos);		
	static enemy* Getenemy();

	static void EnemyCreater();
	D3DXVECTOR3* GetPos();

	void Damage(int nDamage);

	D3DXVECTOR3 m_Epos;

protected:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff; 

	// テクスチャとか
	LPDIRECT3DTEXTURE9 m_pTexture;		

	D3DXVECTOR3 m_rot;

	int m_nELife;                

	static enemy* m_aEnemy[MAX_ENEMY];		
	D3DXMATRIX m_mtxWorld;

	LPD3DXMESH m_pMesh;					
	LPD3DXBUFFER m_pBuffMat;			
	DWORD m_dwNumMat;					

	CInputKeyboard* m_Keyboard;
};

#endif
