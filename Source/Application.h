#pragma once
#include<Windows.h>
#include "Event/EventMapper.h"

class Application
{
private:
	HINSTANCE hInstance;
	HWND hWnd;
	MSG msg;
	LPCTSTR className;
	EventMapper* mapper;

public:
	Application(HINSTANCE);
	bool InitializeWindow();
	bool CreateAppWindow(LPCWSTR title, int x, int y, int width, int height);
	WPARAM Run();

	inline HWND GetHWND() const {return hWnd;}
};