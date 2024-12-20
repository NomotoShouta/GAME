
//==============================
//
// �J��������[camera.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "camera.h"
#include "object.h"
#include "renderer.h"
#include "main.h"
#include "manager.h"
#include "Player.h"
#include "keyboard.h"
#include "input.h"

//===========================================
// �R���X�g���N�^
//===========================================
CCamera::CCamera()
{

}

//===========================================
// �f�X�g���N�^
//===========================================
CCamera::~CCamera()
{

}

//===========================================
// ����������
//===========================================
HRESULT CCamera::Init()
{
	// �����o�ϐ��̏����ݒ�
	m_posV = D3DXVECTOR3(0.0f, 800.0f, -300.0f);	
	m_posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		
	m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);	
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_mtxProjection;				
	m_mtxView;						
	m_fLength = 250.0f;
	follow = false;

	return S_OK;
}

//===========================================
//�I������
//===========================================
void CCamera::Uninit()
{

}

//===========================================
// �X�V����
//===========================================
void CCamera::Update()
{
	
}

//===========================================
// �ݒ菈��
//===========================================
void CCamera::SetCamera()
{
	// �v���W�F�N�V�����}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxProjection);

	D3DXMatrixPerspectiveFovLH(&m_mtxProjection,
		D3DXToRadian(45.0f),
		(float)SCREEN_WIDTH / (float)SCREEN_HEIGHT,
		10.0f,
		1000.0f);

	// �f�o�C�X�̎擾
	CRenderer* pRenderer = CManager::GetRenderer();			
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();		

	// �v���W�F�N�V�����}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection);

	// �r���[�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxView);

	// �r���[�}�g���b�N�X�̍쐬
	D3DXMatrixLookAtLH(&m_mtxView,
		&m_posV, &m_posR, &m_vecU);

	// �r���[�}�g���b�N�X��ݒ肷��
	pDevice->SetTransform(D3DTS_VIEW, &m_mtxView);
}
