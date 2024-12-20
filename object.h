//==============================
//
// �I�u�W�F�N�g����[object.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _OBJECT_H_// ���̃}�N����`������ĂȂ�������
#define _OBJECT_H_// �Q�d�C���N���[�h�h�~�̃}�N����`

#include <Windows.h>
#include "d3dx9.h"

#define MAX_OBJECT  (200)// �I�u�W�F�N�g�̍ő吔

// �I�u�W�F�N�g�N���X
class CObject
{
public:

	typedef enum
	{
		NONE = 0,	
		ENEMY,		
		PLAYER		
	}TYPE;

	CObject();			// �R���X�g���N�^
	virtual ~CObject();	// �f�X�g���N�^

	virtual HRESULT Init();	// ����������
	virtual void Uninit();	// �I������
	virtual void Update();	// �X�V����
	virtual void Draw();	// �`�揈��

	static void ReleaseAll();	
	static void UpdateAll();	
	static void DrawAll();		

	static CObject* GetObject(int nIdx);
	TYPE GetType();						
	void SetType(TYPE type);			

	void Release();// �������g�̉������

private:
	static CObject* m_apObject[MAX_OBJECT];	
	static int m_nNumAll;					
	int m_nID;								
	TYPE m_type;							
};

#endif
