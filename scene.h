//==============================
//
// �V�[������[scene.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _SCENE_H_ // ���̃}�N����`������ĂȂ�������
#define _SCENE_H_// �Q�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "renderer.h"
#include "object2D.h"
#include "keyboard.h"

// �}�l�[�W���[�N���X
class CScene
{
public:

	// ��ʂ̎��
	typedef enum
	{
		MODE_TITLE = 0,
		MODE_TUTORIAL,
		MODE_GAME,
		MODE_RESULT,
		MODE_MAX
	}MODE;

	CScene();				// �R���X�g���N�^
	virtual ~CScene();		// �f�X�g���N�^
	virtual HRESULT Init();	// ����������
	virtual void Uninit();	// �I������
	virtual void Update();	// �X�V����
	virtual void Draw();	// �`�揈��
	static CScene* Create(MODE mode);

private:
	MODE m_Mode;
	CInputKeyboard* m_Keyboard;
};

#endif

