#pragma once
#include<Windows.h>
#include "InputMapper.h"

class RawInput
{
	static InputMapper* m_inputMapper;
public:
	static void SetInputMapper(InputMapper* im) { m_inputMapper = im; }
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
};