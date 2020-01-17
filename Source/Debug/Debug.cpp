#include "Debug.h"

void Debug::Init()
{

}

void Debug::Log(std::string msg)
{
	std::cout << "Debug.Log: " << std::endl << msg << std::endl;
}

void Debug::Log(InputEventData _data)
{
	TCHAR title[40];
	GetWindowText(_data.hWnd, title, sizeof(title));
	std::cout << "==== Input Data ====" << std::endl;
	std::wcout << "Calling Window : " << title << std::endl;
	std::cout << "Main Key : "<< KeyCodeToString(_data.mainKey) << std::endl;
	std::cout << "Shift : "<< _data.shift << std::endl;
	std::cout << "Ctrl : " << _data.ctrl << std::endl;
	std::cout << "Alt : " << _data.alt << std::endl;
}

void Debug::Log(MouseEventData _mData)
{
	std::cout << "==== Mouse Data ====" << std::endl;
	std::cout << "Screen X : " << _mData.screenX << std::endl;
	std::cout << "Screen Y : " << _mData.screenY << std::endl;
	std::cout << "Window X : " << _mData.windowX << std::endl;
	std::cout << "Window Y : " << _mData.windowY << std::endl;

	std::cout << "MouseButton : " << KeyCodeToString(_mData.mouseButtonCode) << std::endl;
	std::cout << "Is left Down : " << _mData.isLeftDown << std::endl;
	std::cout << "Is Right Down : " << _mData.isRightDown << std::endl;
	std::cout << "Is Middle Down : " << _mData.isMiddleDown << std::endl;
}

std::string Debug::KeyCodeToString(KeyCode code)
{
	return "Not yet implemented";
}
