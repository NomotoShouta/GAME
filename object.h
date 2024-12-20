//==============================
//
// オブジェクト処理[object.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _OBJECT_H_// このマクロ定義がされてなかったら
#define _OBJECT_H_// ２重インクルード防止のマクロ定義

#include <Windows.h>
#include "d3dx9.h"

#define MAX_OBJECT  (200)// オブジェクトの最大数

// オブジェクトクラス
class CObject
{
public:

	typedef enum
	{
		NONE = 0,	
		ENEMY,		
		PLAYER		
	}TYPE;

	CObject();			// コンストラクタ
	virtual ~CObject();	// デストラクタ

	virtual HRESULT Init();	// 初期化処理
	virtual void Uninit();	// 終了処理
	virtual void Update();	// 更新処理
	virtual void Draw();	// 描画処理

	static void ReleaseAll();	
	static void UpdateAll();	
	static void DrawAll();		

	static CObject* GetObject(int nIdx);
	TYPE GetType();						
	void SetType(TYPE type);			

	void Release();// 自分自身の解放処理

private:
	static CObject* m_apObject[MAX_OBJECT];	
	static int m_nNumAll;					
	int m_nID;								
	TYPE m_type;							
};

#endif
