//==============================
//
// �^�C������[time.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _TIME_H_// ���̃}�N����`������ĂȂ�������
#define _TIME_H_// �Q�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "object2D.h"

// �}�N����`
#define MAX_TIME (256)
#define MAX_DIGIT	(2)
#define START_TIME_POS	(600.0f)
#define START_NUMBER	(0.0f)
#define TIME_RIMIT (60)

// �I�u�W�F�N�g3D�N���X
class CTime : public CObject2D
{
public:
	typedef struct
	{
		D3DXVECTOR3 pos;
		bool bUse;
	}Time;

	CTime();
	~CTime()override;

	HRESULT Init()override;	// ����������
	void Uninit() override;	// �I������
	void Update() override;	// �X�V����
	void Draw() override;	// �`�揈��
	static CTime* Create();
	static CTime* GetObject2D();

	void SetTimePos(D3DXVECTOR3 pos, D3DXVECTOR2 tex);
	void SetTime(void);
	int GetTime(void);

private:
	static CTime* m_apTime;

	// �O���[�o���ϐ�
	LPDIRECT3DTEXTURE9 m_pTextureTime = NULL;
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffTime = NULL;
	Time m_aTime[MAX_TIME];
	float m_fTimeX;
	int m_nFrame = 0;
	int m_nTime = TIME_RIMIT;
};

#endif