//==============================
//
// ���C������[main.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "main.h"
#include "renderer.h"
#include "object.h"
#include "object2D.h"
#include "manager.h"

// �O���[�o���ϐ�
CManager* g_pManager = nullptr;

//===========================================
// ���C���֐�
//===========================================
int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hInstancePrev,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	WNDCLASSEX wcex =
	{
		sizeof(WNDCLASSEX),					
		CS_CLASSDC,							
		WindowProc,							
		0,									
		0,									
		hInstance,							
		LoadIcon(NULL,IDI_APPLICATION),		
		LoadCursor(NULL,IDC_ARROW),			
		(HBRUSH)(COLOR_WINDOW + 2),			
		NULL,								
		CLASS_NAME,							
		LoadIcon(NULL,IDI_APPLICATION)		
	};

	HWND hWnd;	
	MSG msg;	
	RECT rect = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };

	// �E�C���h�E�N���X�̓o�^
	RegisterClassEx(&wcex);

	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

	hWnd = CreateWindowEx(0,		
		CLASS_NAME,					
		WINDOW_NAME,				
		WS_OVERLAPPEDWINDOW,		
		CW_USEDEFAULT,				
		CW_USEDEFAULT,				
		(rect.right - rect.left),	
		(rect.bottom - rect.top),	
		NULL,						
		NULL,						
		hInstance,					
		NULL);						

	// ������������
	g_pManager = new CManager();		

	//����������
	if (FAILED(g_pManager->Init(hInstance, hWnd, TRUE)))
	{//���������������s�����ꍇ
		return -1;
	}


	// �E�B���h�E�̕\��
	ShowWindow(hWnd, nCmdShow);		
	UpdateWindow(hWnd);				

	// ���b�Z�[�W���[�v
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0)
		{
			// windows�̏���
			if (msg.message == WM_QUIT)
			{
				
				break;
			}
			else
			{
				// ���b�Z�[�W�̐ݒ�
				TranslateMessage(&msg);	
				DispatchMessage(&msg);	
			}
		}
		else
		{
			// �X�V����
			g_pManager->Update();
			// �`�揈��
			g_pManager->Draw();
		}
	}

	// �I������
	g_pManager->Uninit();
	delete g_pManager;

	// �E�C���h�E�N���X�̓o�^������
	UnregisterClass(CLASS_NAME, wcex.hInstance);
	return (int)msg.wParam;
}

//===========================================
// �E�C���h�E�v���V�[�W��
//===========================================
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int nID;   

	switch (uMsg)
	{
	case WM_DESTROY:		
		
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:		
		switch (wParam)
		{
		case VK_ESCAPE:		
			nID = MessageBox(hWnd, "�I�����܂����H", "�I�����b�Z�[�W", MB_YESNO);
			if (nID = IDYES)
			{
				DestroyWindow(hWnd);
			}
			break;
		}
		break;
	case WM_CLOSE:
		nID = MessageBox(hWnd, "�I�����܂����H", "�I�����b�Z�[�W", MB_YESNO);
		if (nID == IDYES)
		{
			
			DestroyWindow(hWnd);
		}
		else
		{
			return 0;			
		}
		break;

	case WM_LBUTTONDOWN:		
		
		SetFocus(hWnd);
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}