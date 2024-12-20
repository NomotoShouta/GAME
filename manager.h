//==============================
//
//	�}�l�[�W���[����[Manager.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _MANAGER_H_ // ���̃}�N����`������ĂȂ�������
#define _MANAGER_H_// �Q�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "renderer.h"
#include "keyboard.h"
#include "camera.h"
#include "light.h"
#include "scene.h"

class CRenderer;

// �}�l�[�W���[�N���X
class CManager
{
public:
	CManager();
	~CManager();
	HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);	// ����������
	void Uninit();												// �I������
	void Update();												// �X�V����
	void Draw();												// �`�揈��
	static CRenderer* GetRenderer();
	static CInputKeyboard* GetKeyboard();
	static CCamera* GetCamera();
	static CLight* GetLight();
	static void SetScene(CScene::MODE mode);

	static CManager* GetInstance()
	{
		static CManager instance;
		return &instance;
	}

private:
	static CRenderer* m_pRnderer;
	static CInputKeyboard* m_pKeyboard;
	static CCamera* m_pCamera;
	static CLight* m_pLight;
	static CScene* m_pScene;
};

#endif
