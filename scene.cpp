//==============================
//
// �V�[������[scene.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "scene.h"
#include "title.h"
#include "game.h"
#include "result.h"
#include "object.h"
#include "object2D.h"
#include "renderer.h"
#include "manager.h"
#include "keyboard.h"
#include "input.h"
#include "tutorial.h"

//===========================================
// �R���X�g���N�^
//===========================================
CScene::CScene()
{

}

//===========================================
// �f�X�g���N�^
//===========================================
CScene::~CScene()
{

}

//===========================================
// �����ݒ�
//===========================================
HRESULT CScene::Init()
{
	return S_OK;
}

//===========================================
// �I������
//===========================================
void CScene::Uninit()
{
	CObject::ReleaseAll();
}

//===========================================
// �X�V����
//===========================================
void CScene::Update()
{
	CObject::UpdateAll();
}

//===========================================
// �`�揈��
//===========================================
void CScene::Draw()
{
	CObject::DrawAll();
}

//===========================================
// ��������
//===========================================
CScene* CScene::Create(MODE mode)
{
	CScene* pScene{};
	switch (mode)
	{
	case MODE_TITLE:
		pScene = new CTitle();
		break;
	case MODE_TUTORIAL:
		pScene = new CTutorial();
		break;
	case MODE_GAME:
		pScene = new CGame();
		break;
	case MODE_RESULT:
		pScene = new CResult();
		break;
	}
	pScene->Init();

	return pScene;
}