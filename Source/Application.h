#pragma once
#include<Windows.h>

class EventMapper;
class Game;

class Application
{
private:
	static Application* instance;
	HINSTANCE hInstance;
	HWND hWnd;
	HWND radio_scan;
	HWND radio_extract;
	MSG msg;
	LPCTSTR className;
	EventMapper* mapper;
	Game* game;

public:
	static Application* Instance();
	Application(HINSTANCE);
	bool InitializeWindow();
	bool CreateAppWindow(LPCWSTR title, int x, int y, int width, int height);
	WPARAM Run();

	inline HWND GetHWND() const {return hWnd;}
	inline HINSTANCE GetHINSTANCE() { return hInstance; }
	inline Game* GetGame() { return game; }

	void SetRadioScan(HWND _hWnd);
	void SetRadioExtract(HWND _hWnd);
};