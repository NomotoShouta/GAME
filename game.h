//==============================
//
// �Q�[������[game.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _GAME_H_ // ���̃}�N����`������ĂȂ�������
#define _GAME_H_// �Q�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "renderer.h"
#include "scene.h"
#include "keyboard.h"

class CGame :public CScene
{
public:

	CGame();
	~CGame()override;
	HRESULT Init()override;	// ����������
	void Uninit()override;	// �I������
	void Update()override;	// �X�V����
	void Draw()override;	// �`�揈��
	static CGame* Create(MODE mode);

private:
	MODE m_Mode;
	CInputKeyboard* m_Keyboard;

};

#endif
