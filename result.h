//==============================
//
// ���U���g����[result.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _RESULT_H_ // ���̃}�N����`������ĂȂ�������
#define _RESULT_H_// �Q�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "renderer.h"
#include "scene.h"
#include "keyboard.h"

class CResult :public CScene
{
public:

	CResult();
	~CResult()override;
	HRESULT Init()override;	// ����������
	void Uninit()override;	// �I������
	void Update()override;	// �X�V����
	void Draw()override;	// �`�揈��
	static CResult* Create(MODE mode);

private:
	MODE m_Mode;// ���݂̃��[�h
	CInputKeyboard* m_Keyboard;

	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;  
	LPDIRECT3DTEXTURE9 m_pTexture;		
};

#endif
