//==============================
//
// �e�N�X�`������[bg_re.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef __BG_RE_H_
#define __BG_RE_H_

#include "main.h"
#include "object2D.h"

// �}�N����`
#define BG_RE_VTX_L		(0.0f)
#define BG_RE_VTX_R		(1280.0f)
#define BG_RE_VTX_U		(0.0f)
#define BG_RE_VTX_V		(720.0f)

class CBg_re : public CObject2D
{
public:

	CBg_re();
	~CBg_re()override;

	HRESULT Init()override;	// ����������
	void Uninit() override;	// �I������
	void Update() override;	// �X�V����
	void Draw() override;	// �`�揈��
	static CBg_re* Create();
};

#endif
