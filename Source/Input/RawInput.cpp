#include <windowsx.h>
#include "RawInput.h"
#include "Input.h"
#include "../Event/EventManager.h"
#include "../Event/MouseEvent.h"
#include "../Event/KeyEvent.h"
#include "../Debug/Debug.h"

void SetKeyData(KeyEventData& _data, HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	_data.hWnd = hWnd;
	_data.key = (KeyCode)wParam;
	_data.down = (lParam & 0x400000000) != 0;
}
void SetMouseData(MouseEventData& _mData, HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	_mData.hWnd = hWnd;
	_mData.screenX = GET_X_LPARAM(lParam);
	_mData.screenY = GET_Y_LPARAM(lParam);
	_mData.windowX = GET_X_LPARAM(lParam);
	_mData.windowY = GET_Y_LPARAM(lParam);
	
	/*_mData.isLeftDown = wParam & MK_LBUTTON;
	_mData.isRightDown = wParam & MK_RBUTTON;
	_mData.isMiddleDown = wParam & MK_MBUTTON;*/
}

LRESULT RawInput::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static KeyEventData _kData;
	static MouseEventData _mData;

	//will call event manager register
	switch (msg)
	{
	case WM_LBUTTONDOWN:
		SetMouseData(_mData, hWnd, wParam, lParam);
		_mData.button = KeyCode::Mouse0;
		Input::KeyPressed(KeyCode::Mouse0);
		//EventManager::Instance()->RegisterEvent(_mData.type, &_mData);
		break;
	case WM_LBUTTONUP:
		Input::KeyReleased(KeyCode::Mouse0);
		break;
	case WM_RBUTTONUP:
		Input::KeyReleased(KeyCode::Mouse1);
		break;
	case WM_RBUTTONDOWN:
		Input::KeyPressed(KeyCode::Mouse1);
		break;
	case WM_KEYDOWN:
		SetKeyData(_kData, hWnd, wParam, lParam);
		Input::KeyPressed(_kData.key);
		//EventManager::Instance()->RegisterEvent(_kData.type, &_kData);
		break;
	case WM_KEYUP:
		SetKeyData(_kData, hWnd, wParam, lParam);
		Input::KeyReleased(_kData.key);
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}