#include <windowsx.h>
#include "RawInput.h"
#include "../Application.h"
#include "../Game/Game.h"
#include "Input.h"
#include "../Renderer/Renderer.h"
#include "../Event/EventManager.h"

#include "../Event/MouseEvent.h"
#include "../Event/KeyEvent.h"

#include "../Debug/Debug.h"

enum { COMMAND_SCAN_MODE = 101, COMMAND_EXTRACT_MODE, COMMAND_RESTART, COMMAND_QUIT };

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
	HDC hdc;
	PAINTSTRUCT ps;

	//will call event manager register
	switch (msg)
	{
	case WM_CREATE:
		CreateWindow(TEXT("button"), TEXT("Mode"), WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 5, 256, 80, 70, hWnd, (HMENU)-1, Application::Instance()->GetHINSTANCE(), NULL);
		Application::Instance()->SetRadioScan(CreateWindow(TEXT("button"), TEXT("Scan"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP, 10, 276, 70, 20, hWnd, (HMENU)COMMAND_SCAN_MODE, Application::Instance()->GetHINSTANCE(), NULL));
		Application::Instance()->SetRadioExtract(CreateWindow(TEXT("button"), TEXT("Extract"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, 10, 296, 70, 20, hWnd, (HMENU)COMMAND_EXTRACT_MODE, Application::Instance()->GetHINSTANCE(), NULL));
		CheckRadioButton(hWnd, COMMAND_SCAN_MODE, COMMAND_EXTRACT_MODE, COMMAND_SCAN_MODE);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case COMMAND_SCAN_MODE:
			Application::Instance()->GetGame()->ScanMode();
			break;
		case COMMAND_EXTRACT_MODE:
			Application::Instance()->GetGame()->ExtractMode();
			break;
		}
		break;
	case WM_LBUTTONDOWN:
		SetMouseData(_mData, hWnd, wParam, lParam);
		_mData.button = KeyCode::Mouse0;
		//Debug::Log(_mData);
		Input::MousePressed(KeyCode::Mouse0);
		Input::MouseMoved(_mData.screenX, _mData.screenY);
		//EventManager::Instance()->RegisterEvent(_mData.type, &_mData);
		break;
	case WM_LBUTTONUP:
		SetMouseData(_mData, hWnd, wParam, lParam);
		_mData.button = KeyCode::Mouse0;
		Input::MouseReleased(KeyCode::Mouse0);
		Input::MouseMoved(_mData.screenX, _mData.screenY);
		break;
	case WM_RBUTTONDOWN:
		SetMouseData(_mData, hWnd, wParam, lParam);
		_mData.button = KeyCode::Mouse1;
		Input::MousePressed(KeyCode::Mouse1);
		Input::MouseMoved(_mData.screenX, _mData.screenY);
		break;
	case WM_RBUTTONUP:
		SetMouseData(_mData, hWnd, wParam, lParam);
		_mData.button = KeyCode::Mouse1;
		Input::MouseReleased(KeyCode::Mouse1);
		Input::MouseMoved(_mData.screenX, _mData.screenY);
		break;
	case WM_MBUTTONDOWN:
		SetMouseData(_mData, hWnd, wParam, lParam);
		_mData.button = KeyCode::Mouse2;
		Input::MousePressed(KeyCode::Mouse2);
		Input::MouseMoved(_mData.screenX, _mData.screenY);
		break;
	case WM_MBUTTONUP:
		SetMouseData(_mData, hWnd, wParam, lParam);
		_mData.button = KeyCode::Mouse2;
		Input::MouseReleased(KeyCode::Mouse2);
		Input::MouseMoved(_mData.screenX, _mData.screenY);
		break;
	case WM_MOUSEMOVE:
		SetMouseData(_mData, hWnd, wParam, lParam);
		//_mData.button = KeyCode::Mouse0;
		Input::MouseMoved(_mData.screenX, _mData.screenY);
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
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		Renderer::Instance()->Render(ps);
		EndPaint(hWnd, &ps);
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}