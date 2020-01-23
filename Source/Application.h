#pragma once
#include<Windows.h>

class Application
{
private:
	HINSTANCE hInstance;
	HWND hWnd;
	MSG msg;
	LPCTSTR className;

public:
	Application(HINSTANCE);
	bool InitializeWindow();
	bool CreateAppWindow(LPCWSTR title, int x, int y, int width, int height);
	WPARAM Run();

	HWND GetHWND() const {return hWnd;}
};