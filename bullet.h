//==============================
//
// �e�̏���[bullet.h]
// Author:Nomoto Shouta
//
//==============================

#ifndef _BULLET_H
#define _BULLET_H

#include "object2D.h"
#include "manager.h"

//�e
class CBullet :public CObject2D
{
public:
	CBullet();
	~CBullet()override;
	void Init()override;	// ����������
	void Uninit()override;	// �I������
	void Update()override;	// �X�V����
	void Draw()override;	// �`�揈��
	static HRESULT Load();
	static void Unload();
	static CBullet* Create();
private:
	static LPDIRECT3DTEXTURE9 m_pTextureTemp;
};
#endif