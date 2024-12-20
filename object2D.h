//==============================
//
// �I�u�W�F�N�g2D����[object2D.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _OBJECT2D_H_// ���̃}�N����`������ĂȂ�������
#define _OBJECT2D_H_// �Q�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "object.h"

// �}�N����`
#define VTX_L		(600.0f)
#define VTX_R		(800.0f)
#define VTX_U		(350.0f)
#define VTX_V		(550.0f)
#define nANIMATION	(5)

// �I�u�W�F�N�g2D�N���X
class CObject2D : public CObject
{
public:
	typedef struct
	{
		D3DXVECTOR3 pos;	
		float rhw;			
		D3DCOLOR col;		
		D3DXVECTOR2 tex;	
	}VERTEX_2D;

	CObject2D();			 // �R���X�g���N�^
	~CObject2D() override;   // �f�X�g���N�^

	HRESULT Init()override;	// ����������
	void Uninit() override;	// �I������
	void Update() override;	// �X�V����
	void Draw() override;	// �`�揈��
	static CObject2D* Create();
	static CObject2D* GetObject2D();

	void BindTexture(LPDIRECT3DTEXTURE9 pTex);
	void SetPos(D3DXVECTOR3 pos);
	D3DXVECTOR3* GetPos();

protected:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;   

	// �e�N�X�`���Ƃ�
	LPDIRECT3DTEXTURE9 m_pTexture;		 
	static CObject2D* m_aObject2D;		
	int m_nCounterAnimPlayer;			
	int m_nPatternAnimPlayer;			
	float m_moveLObject = 0.0f;
	float m_moveRObject = 0.125f;
	float m_moveAdd = 0.125f;
	int m_animation = 0;
	VERTEX_2D m_Vertex[4];			

	D3DXVECTOR3 m_pos;				
	D3DXVECTOR3 m_move;				
	int m_nLife;				
};

#endif
