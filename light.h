//==============================
//
// ���C�g����[light.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _LIGHT_H_// ���̃}�N����`������ĂȂ�������
#define _LIGHT_H_// �Q�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"

// �}�N����`
#define MAX_LIGHT	(128)

// ���C�g
class CLight
{
public:
	typedef struct
	{
		D3DLIGHT9 light;	
		D3DXVECTOR3 vecDir;	
	}Light;

	const static int MAX = 8;   

	CLight();   //�R���X�g���N�^
	~CLight();   //�f�X�g���N�^

	void Init();   //����������
	void Uninit();   //�I������
	void Update();   //�X�V����

private:
	Light m_aLight[MAX_LIGHT];   

};
#endif
