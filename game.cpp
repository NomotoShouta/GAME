//==============================
//
// �Q�[������[game.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "game.h"
#include "object.h"
#include "object2D.h"
#include "renderer.h"
#include "manager.h"
#include "keyboard.h"
#include "input.h"
#include "object3D.h"
#include "Player.h"
#include "wall.h"
#include "keyboard.h"
#include "renderer.h"
#include "scene.h"
#include "time.h"

//===========================================
// �R���X�g���N�^
//===========================================
CGame::CGame()
{

}

//===========================================
// �f�X�g���N�^
//===========================================
CGame::~CGame()
{

}

//===========================================
// �����ݒ�
//===========================================
HRESULT CGame::Init()
{
	CWall::Create();
	CObject3D::Create();
	Player::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	CTime::Create();
	return S_OK;
}

//===========================================
// �I������
//===========================================
void CGame::Uninit()
{
	CObject::ReleaseAll();
}

//===========================================
// �X�V����
//===========================================
void CGame::Update()
{

}

//===========================================
// �`�揈��
//===========================================
void CGame::Draw()
{

}

//===========================================
// ��������
//===========================================
CGame* CGame::Create(MODE mode)
{
	CGame* pGame = new CGame;
	pGame->Init();
	return pGame;
}