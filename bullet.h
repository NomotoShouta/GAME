//==============================
//
// 弾の処理[bullet.h]
// Author:Nomoto Shouta
//
//==============================

#ifndef _BULLET_H
#define _BULLET_H

#include "object2D.h"
#include "manager.h"

//弾
class CBullet :public CObject2D
{
public:
	CBullet();
	~CBullet()override;
	void Init()override;	// 初期化処理
	void Uninit()override;	// 終了処理
	void Update()override;	// 更新処理
	void Draw()override;	// 描画処理
	static HRESULT Load();
	static void Unload();
	static CBullet* Create();
private:
	static LPDIRECT3DTEXTURE9 m_pTextureTemp;
};
#endif