//==============================
//
// オブジェクト処理[object.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "object.h"
#include "object2D.h"
#include "bg.h"
#include "object3D.h"

// 静的メンバ初期化
int CObject::m_nNumAll = 0;
CObject* CObject::m_apObject[MAX_OBJECT] = {};

//===========================================
// コンストラクタ
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
// デストラクタ
//===========================================
CObject::~CObject()
{

}

//===========================================
// 初期設定
//===========================================
HRESULT CObject::Init()
{
	return S_OK;
}

//===========================================
// 終了処理
//===========================================
void CObject::Uninit()
{
	
}

//===========================================
// 更新処理
//===========================================
void CObject::Update()
{

}

//===========================================
// 描画処理
//===========================================
void CObject::Draw()
{

}

//===========================================
// 全オブジェクト解放
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
// 全オブジェクト更新
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
// 全オブジェクト描画
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
// 自分自身の解放
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
// オブジェクト取得
//===========================================
CObject* CObject::GetObject(int nIdx)
{
	return m_apObject[nIdx];
}

//===========================================
// タイプ取得
//===========================================
CObject::TYPE CObject::GetType()
{
	return m_type;
}

//===========================================
// タイプ設定
//===========================================
void CObject::SetType(TYPE type)
{
	m_type = type;
}