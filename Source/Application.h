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
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	WPARAM Run();

	HWND GetHWND() {return hWnd;}
};