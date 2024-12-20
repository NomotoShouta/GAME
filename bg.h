//==============================
//
// �o�b�N�O���E���h����[bg.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _BG_H_
#define _BG_H_

#include "main.h"
#include "object2D.h"

// �}�N����`
#define BGVTX_L		(0.0f)
#define BGVTX_R		(1280.0f)
#define BGVTX_U		(0.0f)
#define BGVTX_V		(720.0f)

class CBg : public CObject2D
{
public:

	CBg();
	~CBg()override;

	HRESULT Init()override;	// ����������
	void Uninit() override;	// �I������
	void Update() override;	// �X�V����
	void Draw() override;	// �`�揈��
	static CBg* Create();

};

#endif
