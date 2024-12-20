//==============================
//
// �Ǐ���[wall.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _WALL_H_// ���̃}�N����`������ĂȂ�������
#define _WALL_H_// �Q�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "object.h"
#include "renderer.h"

// �I�u�W�F�N�g3D�N���X
class CWall : public CObject
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

	CWall();					// �R���X�g���N�^
	~CWall() override;			// �f�X�g���N�^

	HRESULT Init()override;		// ����������
	void Uninit() override;		// �I������
	void Update() override;		// �X�V����
	void Draw() override;		// �`�揈��
	static CWall* Create();		
	static HRESULT Load();			
	static void Unload();			
	static CWall* GetWall();

protected:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff; 

	LPDIRECT3DTEXTURE9 m_pTexture;		
	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_rot;

	static CWall* m_aWall;		
	D3DXMATRIX m_mtxWorld;
};

#endif
