//==============================
//
// �I�u�W�F�N�g3D����[object3D.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _OBJECT3D_H_// ���̃}�N����`������ĂȂ�������
#define _OBJECT3D_H_// �Q�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "object.h"
#include "renderer.h"

// �I�u�W�F�N�g3D�N���X
class CObject3D : public CObject
{
public:
	// ���_���̍\���̂��`
	typedef struct
	{
		D3DXVECTOR3 pos;	
		D3DXVECTOR3 nor;	
		D3DCOLOR col;		
		D3DXVECTOR2 tex;	
	}VERTEX_3D;

	typedef struct
	{
		D3DXVECTOR3 pos;	
		float rhw;			
		D3DCOLOR col;		
		D3DXVECTOR2 tex;	
	}VERTEX_2D;

	CObject3D();					// �R���X�g���N�^
	~CObject3D() override;			// �f�X�g���N�^

	HRESULT Init()override;			// ����������
	void Uninit() override;			// �I������
	void Update() override;			// �X�V����
	void Draw() override;			// �`�揈��
	void BindTexture(LPDIRECT3DTEXTURE9 pTex);
	D3DXVECTOR3& GetPos() { return m_pos; }
	static CObject3D* Create();		
	static HRESULT Load();			
	static void Unload();			
	static CObject3D* GetObject3D();


protected:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;  

	// �e�N�X�`���Ƃ�
	LPDIRECT3DTEXTURE9 m_pTexture;		
	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_rot;

	static CObject3D* m_aObject3D;		
	D3DXMATRIX m_mtxWorld;
};

#endif

