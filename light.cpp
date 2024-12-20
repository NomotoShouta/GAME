//==============================
//
// ���C�g����[light.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "light.h"
#include "object.h"
#include "renderer.h"
#include "main.h"
#include "manager.h"

//===========================================
// �R���X�g���N�^
//===========================================
CLight::CLight()
{
	
}

//===========================================
// �f�X�g���N�^
//===========================================
CLight::~CLight()
{

}

//===========================================
// ����������
//===========================================
void CLight::Init()
{
	// �f�o�C�X���擾����
	CRenderer* pRenderer = CManager::GetRenderer();		
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	int nCntLight;

	D3DXVECTOR3 vecDir;

	m_aLight[0].vecDir = D3DXVECTOR3(0.5f, -0.9f, 0.5f);
	m_aLight[1].vecDir = D3DXVECTOR3(-0.2f, 0.9f, -0.5f);
	m_aLight[2].vecDir = D3DXVECTOR3(0.9f, 0.1f, 0.5f);

	for (nCntLight = 0; nCntLight < CLight::MAX; nCntLight++)
	{
		// ���C�g�̏����N���A����
		ZeroMemory(&m_aLight[nCntLight].light, sizeof(D3DLIGHT9));

		// ���C�g�̎�ނ�ݒ�
		m_aLight[nCntLight].light.Type = D3DLIGHT_DIRECTIONAL;   

		// ���C�g�̊g�U����ݒ�
		m_aLight[nCntLight].light.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);   

		// ���C�g�̕�����ݒ�
		vecDir = m_aLight[nCntLight].vecDir;
		D3DXVec3Normalize(&vecDir, &vecDir);
		m_aLight[nCntLight].light.Direction = vecDir;

		// ���C�g��ݒ肷��
		pDevice->SetLight(nCntLight, &m_aLight[nCntLight].light);

		// ���C�g��L���ɂ���
		pDevice->LightEnable(nCntLight, TRUE);
	}
}

//===========================================
//�I������
//===========================================
void CLight::Uninit()
{

}

//===========================================
//�X�V����
//===========================================
void CLight::Update()
{

}