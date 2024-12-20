//==============================
//
// メイン処理[main.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "main.h"
#include "renderer.h"
#include "object.h"
#include "object2D.h"
#include "manager.h"

// グローバル変数
CManager* g_pManager = nullptr;

//===========================================
// メイン関数
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

	// ウインドウクラスの登録
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

	// 生成＆初期化
	g_pManager = new CManager();		

	//初期化処理
	if (FAILED(g_pManager->Init(hInstance, hWnd, TRUE)))
	{//初期化処理が失敗した場合
		return -1;
	}


	// ウィンドウの表示
	ShowWindow(hWnd, nCmdShow);		
	UpdateWindow(hWnd);				

	// メッセージループ
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0)
		{
			// windowsの処理
			if (msg.message == WM_QUIT)
			{
				
				break;
			}
			else
			{
				// メッセージの設定
				TranslateMessage(&msg);	
				DispatchMessage(&msg);	
			}
		}
		else
		{
			// 更新処理
			g_pManager->Update();
			// 描画処理
			g_pManager->Draw();
		}
	}

	// 終了処理
	g_pManager->Uninit();
	delete g_pManager;

	// ウインドウクラスの登録を解除
	UnregisterClass(CLASS_NAME, wcex.hInstance);
	return (int)msg.wParam;
}

//===========================================
// ウインドウプロシージャ
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
			nID = MessageBox(hWnd, "終了しますか？", "終了メッセージ", MB_YESNO);
			if (nID = IDYES)
			{
				DestroyWindow(hWnd);
			}
			break;
		}
		break;
	case WM_CLOSE:
		nID = MessageBox(hWnd, "終了しますか？", "終了メッセージ", MB_YESNO);
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