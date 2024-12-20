//==============================
//
// �I�u�W�F�N�g����[object.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "object.h"
#include "object2D.h"
#include "bg.h"
#include "object3D.h"

// �ÓI�����o������
int CObject::m_nNumAll = 0;
CObject* CObject::m_apObject[MAX_OBJECT] = {};

//===========================================
// �R���X�g���N�^
//===========================================
CObject::CObject()
{
	int nCnt;
	for (nCnt = 0; nCnt < MAX_OBJECT; nCnt++)
	{
		if (m_apObject[nCnt] == nullptr)
		{
			m_apObject[nCnt] = this;	
			m_nID = nCnt;				
			m_nNumAll++;				
			break;						
		}
	}
}

//===========================================
// �f�X�g���N�^
//===========================================
CObject::~CObject()
{

}

//===========================================
// �����ݒ�
//===========================================
HRESULT CObject::Init()
{
	return S_OK;
}

//===========================================
// �I������
//===========================================
void CObject::Uninit()
{
	
}

//===========================================
// �X�V����
//===========================================
void CObject::Update()
{

}

//===========================================
// �`�揈��
//===========================================
void CObject::Draw()
{

}

//===========================================
// �S�I�u�W�F�N�g���
//===========================================
void CObject::ReleaseAll()
{
	for (int nCnt = 0; nCnt < MAX_OBJECT; nCnt++)
	{
		if (m_apObject[nCnt] != nullptr)
		{
			m_apObject[nCnt]->Uninit();

			delete m_apObject[nCnt];

			m_apObject[nCnt] = nullptr;

			m_nNumAll--;
		}
	}
}

//===========================================
// �S�I�u�W�F�N�g�X�V
//===========================================
void CObject::UpdateAll()
{
	for (int nCnt = 0; nCnt < MAX_OBJECT; nCnt++)
	{
		if (m_apObject[nCnt] != nullptr)
		{
			m_apObject[nCnt]->Update();
		}
	}
}

//===========================================
// �S�I�u�W�F�N�g�`��
//===========================================
void CObject::DrawAll()
{
	for (int nCnt = 0; nCnt < MAX_OBJECT; nCnt++)
	{
		if (m_apObject[nCnt] != nullptr)
		{
			m_apObject[nCnt]->Draw();
		}
	}
}

//===========================================
// �������g�̉��
//===========================================
void CObject::Release()
{
	int nID = m_nID;
	if (m_apObject[nID] != nullptr)
	{
		delete m_apObject[nID];
		m_apObject[nID] = nullptr;
		m_nNumAll--;
	}
}

//===========================================
// �I�u�W�F�N�g�擾
//===========================================
CObject* CObject::GetObject(int nIdx)
{
	return m_apObject[nIdx];
}

//===========================================
// �^�C�v�擾
//===========================================
CObject::TYPE CObject::GetType()
{
	return m_type;
}

//===========================================
// �^�C�v�ݒ�
//===========================================
void CObject::SetType(TYPE type)
{
	m_type = type;
}