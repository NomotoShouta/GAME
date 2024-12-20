//==============================
//
// ゲーム処理[game.cpp]
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
// コンストラクタ
//===========================================
CGame::CGame()
{

}

//===========================================
// デストラクタ
//===========================================
CGame::~CGame()
{

}

//===========================================
// 初期設定
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
// 終了処理
//===========================================
void CGame::Uninit()
{
	CObject::ReleaseAll();
}

//===========================================
// 更新処理
//===========================================
void CGame::Update()
{

}

//===========================================
// 描画処理
//===========================================
void CGame::Draw()
{

}

//===========================================
// 生成処理
//===========================================
CGame* CGame::Create(MODE mode)
{
	CGame* pGame = new CGame;
	pGame->Init();
	return pGame;
}