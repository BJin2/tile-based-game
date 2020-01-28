#pragma once
#include <Windows.h>

class Renderer
{
private :
	static Renderer* instance;
	HWND hWnd;

public :
	static Renderer* Instance();
	void SetHWND(HWND _hWnd);
	void Render(const HDC& hdc);
};