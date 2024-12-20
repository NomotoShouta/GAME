//==============================
//
// ”š”­ˆ—[explosion.h]
// Author:Nomoto Shouta
//
//==============================
#include "object3D.h"

//”š”­
class CExplosion :public CObject3D
{
public:
	CExplosion();
	~CExplosion();

	//HRESULT Init()override;	// ‰Šú‰»ˆ—
	void Uninit();
	void Update();
	void Draw();
	static CExplosion* Create();
private:
	//ƒƒ“ƒo

};
