#include "Renderer.h"

Renderer* Renderer::instance;
Renderer* Renderer::Instance()
{
	if (instance)
		return instance;
	else
		return instance = new Renderer();
}

void Renderer::SetHWND(HWND _hWnd)
{
	hWnd = _hWnd;
}

void Renderer::Render(const HDC& hdc)
{
	SetPixel(hdc, 10, 10, RGB(0, 255, 0));
	MoveToEx(hdc, 50, 50, NULL);
	LineTo(hdc, 300, 90);
	Rectangle(hdc, 50, 100, 200, 180);
}