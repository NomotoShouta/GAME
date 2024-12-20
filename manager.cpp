//==============================
//
//	�}�l�[�W���[����[Manager.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "manager.h"
#include "input.h"
#include "joypad.h"


// �ÓI�����o������
CRenderer* CManager::m_pRnderer = nullptr;
CInputKeyboard* CManager::m_pKeyboard = nullptr;
CCamera* CManager::m_pCamera = nullptr;
CLight* CManager::m_pLight = nullptr;
CScene* CManager::m_pScene = nullptr;

//===========================================
// �R���X�g���N�^
//===========================================
CManager::CManager()
{

}

//===========================================
// �f�X�g���N�^
//===========================================
CManager::~CManager()
{

}

//===========================================
// �����ݒ�
//===========================================
HRESULT CManager::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// �����_���[�̐���
	m_pRnderer = new CRenderer();
	m_pRnderer->Init(hWnd, bWindow);

	// �L�[�{�[�h�̐���
	m_pKeyboard = new CInputKeyboard();
	m_pKeyboard->Init(hInstance, hWnd);

	// �J�����̐���
	m_pCamera = new CCamera();
	m_pCamera->Init();

	// ���C�g�̐���
	m_pLight = new CLight();
	m_pLight->Init();

	SetScene(CScene::MODE::MODE_TITLE);

	////�W���C�p�b�g�̏���������
	//if (FAILED(InitJoypad()))
	//{
	//	return E_FAIL;
	//}

	return S_OK;
}

//===========================================
// �I������
//===========================================
void CManager::Uninit()
{
	CObject::ReleaseAll();

	// �����_���[
	if (m_pRnderer != nullptr)
	{
		m_pRnderer->Uninit();
		delete m_pRnderer;
		m_pRnderer = nullptr;
	}

	// �L�[�{�[�h
	if (m_pKeyboard != nullptr)
	{
		m_pKeyboard->Uninit();
		delete m_pKeyboard;
		m_pKeyboard = nullptr;
	}

	// �J����
	if (m_pCamera != nullptr)
	{
		m_pCamera->Uninit();
		delete m_pCamera;
		m_pCamera = nullptr;
	}

	// ���C�g
	if (m_pLight != nullptr)
	{

		m_pLight->Uninit();
		delete m_pLight;
		m_pLight = nullptr;
	}
}

//===========================================
// �X�V����
//===========================================
void CManager::Update()
{
	// �����_���[
	if (m_pRnderer != nullptr)
	{
		m_pRnderer->Update();
	}

	// �L�[�{�[�h
	if (m_pKeyboard != nullptr)
	{
		m_pKeyboard->Update();
	}

	// �J����
	if (m_pCamera != nullptr)
	{
		m_pCamera->Update();
	}

	// ���C�g
	if (m_pLight != nullptr)
	{
		m_pLight->Update();
	}

	// scene
	if (m_pScene != nullptr)
	{
		m_pScene->Update();
	}


	
}

//===========================================
// �`�揈��
//===========================================
void CManager::Draw()
{
	// �����_���[
	if (m_pRnderer != nullptr)
	{
		m_pRnderer->Draw();
	}
}

//===========================================
// �����_���[�擾
//===========================================
CRenderer* CManager::GetRenderer()
{
	return m_pRnderer;
}

//===========================================
// �L�[�{�[�h�擾
//===========================================
CInputKeyboard* CManager::GetKeyboard()
{
	return m_pKeyboard;
}

//===========================================
// �J�����擾
//===========================================
CCamera* CManager::GetCamera()
{
	return m_pCamera;
}

//===========================================
// ���C�g�擾
//===========================================
CLight* CManager::GetLight()
{
	return m_pLight;
}

//===========================================
// �Z�b�g���[�h
//===========================================
void CManager::SetScene(CScene::MODE mode)
{
	
	if (m_pScene != nullptr)
	{
		m_pScene->Uninit();
		

		delete m_pScene;
		m_pScene = nullptr;
	}

	m_pScene = CScene::Create(mode);
}