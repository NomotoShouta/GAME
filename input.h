//==============================
//
// �C���v�b�g����[input.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _INPUT_H_ // ���̃}�N����`������ĂȂ�������
#define _INPUT_H_// �Q�d�C���N���[�h�h�~�̃}�N����`

#include <Windows.h>
#include "d3dx9.h"
#include "main.h"

#define MAX_KEY	(256)

// �����_���[�N���X
class CInput
{
public:
	CInput();// �R���X�g���N�^
	~CInput();// �f�X�g���N�^

	virtual HRESULT Init(HINSTANCE hInstance, HWND hWnd);// ����������
	virtual void Uninit();// �I������
	virtual void Update() = 0;// �X�V����

protected:
	static LPDIRECTINPUT8 m_pInput;
	LPDIRECTINPUTDEVICE8 m_pDevice;
};
#endif
