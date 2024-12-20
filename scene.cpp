//==============================
//
// シーン処理[scene.cpp]
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
// コンストラクタ
//===========================================
CScene::CScene()
{

}

//===========================================
// デストラクタ
//===========================================
CScene::~CScene()
{

}

//===========================================
// 初期設定
//===========================================
HRESULT CScene::Init()
{
	return S_OK;
}

//===========================================
// 終了処理
//===========================================
void CScene::Uninit()
{
	CObject::ReleaseAll();
}

//===========================================
// 更新処理
//===========================================
void CScene::Update()
{
	CObject::UpdateAll();
}

//===========================================
// 描画処理
//===========================================
void CScene::Draw()
{
	CObject::DrawAll();
}

//===========================================
// 生成処理
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