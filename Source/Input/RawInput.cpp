#include <windowsx.h>
#include "RawInput.h"
#include "../Event/InputEvent.h"
#include "../Event/MouseEvent.h"
#include "../Event/KeyEvent.h"
#include "../Debug/Debug.h"

InputMapper* RawInput::m_inputMapper;

void SetInputData(InputEventData& _data, HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	_data.ctrl = GetKeyState(VK_CONTROL) < 0;
	_data.shift = GetKeyState(VK_SHIFT) < 0;
	_data.hWnd = hWnd;
	_data.mainKey = (KeyCode)wParam;
	_data.wasDown = (lParam & 0x400000000) != 0;
}
void SetMouseData(MouseEventData& _mData, HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	_mData.screenX = GET_X_LPARAM(lParam);
	_mData.screenY = GET_Y_LPARAM(lParam);
	_mData.windowX = GET_X_LPARAM(lParam);
	_mData.windowY = GET_Y_LPARAM(lParam);
	_mData.isLeftDown = wParam & MK_LBUTTON;
	_mData.isRightDown = wParam & MK_RBUTTON;
	_mData.isMiddleDown = wParam & MK_MBUTTON;
}

LRESULT RawInput::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static InputEventData _data;
	static MouseEventData _mData;

	switch (msg)
	{
	case WM_LBUTTONDOWN:
		SetInputData(_data, hWnd, wParam, lParam);
		SetMouseData(_mData, hWnd, wParam, lParam);
		_mData.mouseButtonCode = KeyCode::Mouse0;
		_data.eventType = EventType::MouseEvent;
		m_inputMapper->RegisterMouseEvent(_mData, _data, HandlerCode::OnMousePressed);
		break;
	case WM_KEYDOWN:
		SetInputData(_data, hWnd, wParam, lParam);
		_data.eventType = EventType::KeyEvent;
		m_inputMapper->RegisterKeyEvent(_data, HandlerCode::OnKeyPressed);
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}