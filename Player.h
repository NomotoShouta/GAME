//==============================
//
// プレイヤー処理[Player.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _PLAYER_H_// このマクロ定義がされてなかったら
#define _PLAYER_H_// ２重インクルード防止のマクロ定義

#include "main.h"
#include "object.h"
#include "renderer.h"
#include "manager.h"

// マクロ定義
#define MAX_COOLTIME (30)
#define MAX_COOLTIMEMR (60)
#define MAX_COOLTIMESP (180)

// オブジェクトXクラス
class Player : public CObject
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

	Player();					// コンストラクタ
	~Player() override;			// デストラクタ

	HRESULT Init()override;			// 初期化処理
	void Uninit() override;			// 終了処理
	void Update() override;			// 更新処理
	void Draw() override;			// 描画処理
	static Player* Create(D3DXVECTOR3 pos);
	static HRESULT Load();			
	static void Unload();			
	static Player* GetPlayer();

	D3DXVECTOR3* GetPos();

	D3DXVECTOR3 m_pos;

protected:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff; 

	
	LPDIRECT3DTEXTURE9 m_pTexture;		 

	D3DXVECTOR3 m_rot;
	D3DXVECTOR3 m_move;
	D3DXVECTOR3 m_posOld;

	int m_nCntCooltime;
	int m_nCntCooltimeMR;
	int m_nCntCooltimeSP;

	static Player* m_aPlayer;

	D3DXMATRIX m_mtxWorld;
	LPD3DXMESH m_pMesh;					
	LPD3DXBUFFER m_pBuffMat;			
	DWORD m_dwNumMat;					

	CInputKeyboard* m_Keyboard;

	CCamera* m_Camera;
};

#endif


