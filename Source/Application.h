#pragma once
#include<Windows.h>
#include"Input/InputMapper.h"
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
	void Shutdow();

	void SetScene(Scene scene);
	Scene m_scene;

	InputMapper m_inputMapper;

	HWND GetHWND() {return hWnd;}
};