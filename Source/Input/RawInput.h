#pragma once
#include<Windows.h>

class RawInput
{
public:
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
};