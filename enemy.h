//==============================
//
// �G�P����[enemy.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _ENEMY_H_// ���̃}�N����`������ĂȂ�������
#define _ENEMY_H_// �Q�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "object.h"
#include "renderer.h"
#include "manager.h"

// �}�N����`
#define MAX_ENEMY (200)

// �I�u�W�F�N�gX�N���X
class enemy : public CObject
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

	enemy();				// �R���X�g���N�^
	~enemy() override;		// �f�X�g���N�^

	HRESULT Init()override;			// ����������
	void Uninit() override;			// �I������
	void Update() override;			// �X�V����
	void Draw() override;			// �`�揈��
	static enemy* Create(D3DXVECTOR3 pos);		
	static enemy* Getenemy();

	static void EnemyCreater();
	D3DXVECTOR3* GetPos();

	void Damage(int nDamage);

	D3DXVECTOR3 m_Epos;

protected:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff; 

	// �e�N�X�`���Ƃ�
	LPDIRECT3DTEXTURE9 m_pTexture;		

	D3DXVECTOR3 m_rot;

	int m_nELife;                

	static enemy* m_aEnemy[MAX_ENEMY];		
	D3DXMATRIX m_mtxWorld;

	LPD3DXMESH m_pMesh;					
	LPD3DXBUFFER m_pBuffMat;			
	DWORD m_dwNumMat;					

	CInputKeyboard* m_Keyboard;
};

#endif
