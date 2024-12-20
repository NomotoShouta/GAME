//==============================
//
// �J��������[camera.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _CAMERA_H_// ���̃}�N����`������ĂȂ�������
#define _CAMERA_H_// �Q�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "object.h"
#include "renderer.h"

// �I�u�W�F�N�g3D�N���X
class CCamera
{
public:

	CCamera();			// �R���X�g���N�^
	~CCamera();			// �f�X�g���N�^

	HRESULT Init();		// ����������
	void Uninit();		// �I������
	void Update();		// �X�V����
	void SetCamera();	

private:
	D3DXVECTOR3 m_posV;				
	D3DXVECTOR3 m_posR;				
	D3DXVECTOR3 m_vecU;				
	D3DXVECTOR3 m_rot;				
	D3DXMATRIX m_mtxProjection;		
	D3DXMATRIX m_mtxView;			
	float m_fLength;				
	bool follow;					

};

#endif
