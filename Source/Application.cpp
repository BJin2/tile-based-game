#include "Application.h"

Application::Application(HINSTANCE _hInstance)
{
	hInstance = _hInstance;
	hWnd = 0;
	className = TEXT("");
	msg = MSG();
}

bool Application::InitializeWindow()
{
	WNDCLASS wc;

	//Set windows class
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = className;
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	//Register windows class
	if (!RegisterClass(&wc))
		return false;
	return true;
}

bool Application::CreateAppWindow(LPCWSTR title, int x, int y, int width, int height)
{
	className = title;
	if (!InitializeWindow())
		return false;

	//Create windows
	this->hWnd = CreateWindow(className, className, WS_OVERLAPPEDWINDOW, x, y, width, height, NULL, (HMENU)NULL, hInstance, NULL);
	if (!this->hWnd)
		return false;

	ShowWindow(this->hWnd, SW_SHOW);
	UpdateWindow(this->hWnd);

	return true;
}

WPARAM Application::Run()
{
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT Application::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}
