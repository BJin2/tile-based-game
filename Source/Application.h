#pragma once
#include<Windows.h>
#include"Scene.h"

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

	void SetScene(Scene scene);
	Scene m_scene;

	HWND GetHWND() {return hWnd;}
};