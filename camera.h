//==============================
//
// カメラ処理[camera.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _CAMERA_H_// このマクロ定義がされてなかったら
#define _CAMERA_H_// ２重インクルード防止のマクロ定義

#include "main.h"
#include "object.h"
#include "renderer.h"

// オブジェクト3Dクラス
class CCamera
{
public:

	CCamera();			// コンストラクタ
	~CCamera();			// デストラクタ

	HRESULT Init();		// 初期化処理
	void Uninit();		// 終了処理
	void Update();		// 更新処理
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
