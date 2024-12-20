//==============================
//
// �^�C�g������[title.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _TITLE_H_ // ���̃}�N����`������ĂȂ�������
#define _TITLE_H_// �Q�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "renderer.h"
#include "scene.h"
#include "keyboard.h"

class CTitle :public CScene
{
public:

	CTitle();
	~CTitle()override;
	HRESULT Init()override;	// ����������
	void Uninit()override;	// �I������
	void Update()override;	// �X�V����
	void Draw()override;	// �`�揈��
	static CTitle* Create(MODE mode);

private:
	MODE m_Mode;
	CInputKeyboard* m_Keyboard;
	/*CObject2D* pBg;*/
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;   
	LPDIRECT3DTEXTURE9 m_pTexture;		 
};

#endif