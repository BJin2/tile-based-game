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
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	WPARAM Run();

	HWND GetHWND() {return hWnd;}
};