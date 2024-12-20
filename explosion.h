//==============================
//
// 爆発処理[explosion.h]
// Author:Nomoto Shouta
//
//==============================
#include "object3D.h"

//爆発
class CExplosion :public CObject3D
{
public:
	CExplosion();
	~CExplosion();

	//HRESULT Init()override;	// 初期化処理
	void Uninit();
	void Update();
	void Draw();
	static CExplosion* Create();
private:
	//メンバ

};
