//==============================
//
// �`���[�g���A������[tutorial.h]
// Author:Nomoto Shouta
//
//==============================

#ifndef _TUTORIAL_H
#define _TUTORIAL_H

#include "main.h"
#include "renderer.h"
#include "scene.h"
#include "keyboard.h"

class CTutorial :public CScene
{
public:

	CTutorial();
	~CTutorial()override;
	HRESULT Init()override;	// ����������
	void Uninit()override;	// �I������
	void Update()override;	// �X�V����
	void Draw()override;	// �`�揈��
	static CTutorial* Create(MODE mode);

private:
	MODE m_Mode;// ���݂̃��[�h
	CInputKeyboard* m_Keyboard;
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;
	LPDIRECT3DTEXTURE9 m_pTexture;
};
#endif