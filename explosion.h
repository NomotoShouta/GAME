//==============================
//
// ��������[explosion.h]
// Author:Nomoto Shouta
//
//==============================
#include "object3D.h"

//����
class CExplosion :public CObject3D
{
public:
	CExplosion();
	~CExplosion();

	//HRESULT Init()override;	// ����������
	void Uninit();
	void Update();
	void Draw();
	static CExplosion* Create();
private:
	//�����o

};
