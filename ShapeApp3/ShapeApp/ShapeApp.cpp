// ShapeApp.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "ShapeApp.h"
#include "Shape.h"
#include "Point.h"
#include "Ellipse.h"
#include "Rect.h"
#include"Polygon.h"



#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_SHAPEAPP, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SHAPEAPP));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SHAPEAPP));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_SHAPEAPP);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	double arr[16] = { 100, 300, 500, 400, 100, 120, 130, 140, 150, 160, 170, 180, 190, 210, 230, 250 };
	static CShape *aS[] = { new CEllipse(400, 250, 200, 100), new CMyRect(200, 100, 300, 200) , new Circle(450,250,200), new CPolygon(arr) };
	static CShape *bS[] = { new CEllipse(400, 250, 200, 100), new CMyRect(200, 100, 300, 200) , new Circle(450,250,200) , new CPolygon(arr) };
	static int h = 0, n = sizeof(aS)/sizeof(aS[0]);
	static int k = 0, m = sizeof(bS) / sizeof(bS[0]);
	static CShape *pS = aS[h];
	static CShape *qS = bS[k];
	
	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	
	case WM_CHAR:
		switch (TCHAR(wParam))
		{
		case '{':
			if (++h == n) h = 0;
			pS = aS[h];
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case '}':
			if (++k == m) k = 0;
			qS = aS[k];
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case '=':
			pS->Scale(1.2);
			InvalidateRect(hWnd, NULL, TRUE);
			break;		
		case '-':
			pS->Scale(1/1.2);
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case '+':
			qS->Scale(1.2);
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case '_':
			qS->Scale(1 / 1.2);
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 'a':
			qS->Move(-10, 0);
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 'd':
			qS->Move(10, 0);
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 'w':
			qS->Move(0, -10);
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 's':
			qS->Move(0, 10);
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		}
		break;

	case WM_KEYDOWN:
		switch(wParam){
		case VK_LEFT: 
			pS->Move(-10, 0);
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_RIGHT:  
			pS->Move(10, 0);
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_UP: 
			pS->Move(0, -10);
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_DOWN: 
			pS->Move(0, 10);
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		}

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		HPEN hpen;
		hpen = CreatePen(PS_SOLID, 4, RGB(255, 0, 0));
		SelectObject(hdc, hpen);
		HBRUSH hbr;
		hbr = CreateSolidBrush(RGB(0, 255, 255));
		SelectObject(hdc, hpen);
		SelectObject(hdc, hbr);

		pS->Draw(hdc);
		qS->Draw(hdc);

		DeleteObject(hbr);
		DeleteObject(hpen);
		
		EndPaint(hWnd, &ps);
		break;
	
	case WM_DESTROY:
		delete pS;
		delete qS;
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}



// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
