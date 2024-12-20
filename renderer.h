//==============================
//
// �����_���[����[renderer.h]
// Author:Nomoto Shouta
//
//==============================
#ifndef _RENDERER_H_ // ���̃}�N����`������ĂȂ�������
#define _RENDERER_H_// �Q�d�C���N���[�h�h�~�̃}�N����`

#include <Windows.h>
#include "d3dx9.h"
#include "main.h"

// �����_���[�N���X
class CRenderer
{
public:
	CRenderer();// �R���X�g���N�^
	~CRenderer();// �f�X�g���N�^

	HRESULT Init(HWND hWnd, BOOL bWindow);
	void Uninit();// �I������
	void Update();// �X�V����
	void Draw();// �`�揈��
	LPDIRECT3DDEVICE9 GetDevice();

private:
	LPDIRECT3D9 m_pD3D;						
	LPDIRECT3DDEVICE9 m_pD3DDevice;			
};

#endif
