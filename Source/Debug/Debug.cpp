#include "Debug.h"

void Debug::Init()
{
	static bool initialized = false;
	if (initialized)
		return;
	initialized = true;

	_enumStringMap.insert(std::make_pair(KeyCode::NO_CODE, "NO_CODE"));

	_enumStringMap.insert(std::make_pair(KeyCode::Mouse_0, "Mouse 0"));
	_enumStringMap.insert(std::make_pair(KeyCode::Mouse_1, "Mouse 1"));
	_enumStringMap.insert(std::make_pair(KeyCode::Mouse_2, "Mouse 2"));

	_enumStringMap.insert(std::make_pair(KeyCode::A, "A"));
	_enumStringMap.insert(std::make_pair(KeyCode::B, "B"));
	_enumStringMap.insert(std::make_pair(KeyCode::C, "C"));
	_enumStringMap.insert(std::make_pair(KeyCode::D, "D"));
	_enumStringMap.insert(std::make_pair(KeyCode::E, "E"));
	_enumStringMap.insert(std::make_pair(KeyCode::F, "F"));
	_enumStringMap.insert(std::make_pair(KeyCode::G, "G"));
	_enumStringMap.insert(std::make_pair(KeyCode::H, "H"));
	_enumStringMap.insert(std::make_pair(KeyCode::I, "I"));
	_enumStringMap.insert(std::make_pair(KeyCode::J, "J"));
	_enumStringMap.insert(std::make_pair(KeyCode::K, "K"));
	_enumStringMap.insert(std::make_pair(KeyCode::L, "L"));
	_enumStringMap.insert(std::make_pair(KeyCode::M, "M"));
	_enumStringMap.insert(std::make_pair(KeyCode::N, "N"));
	_enumStringMap.insert(std::make_pair(KeyCode::O, "O"));
	_enumStringMap.insert(std::make_pair(KeyCode::P, "P"));
	_enumStringMap.insert(std::make_pair(KeyCode::Q, "Q"));
	_enumStringMap.insert(std::make_pair(KeyCode::R, "R"));
	_enumStringMap.insert(std::make_pair(KeyCode::S, "S"));
	_enumStringMap.insert(std::make_pair(KeyCode::T, "T"));
	_enumStringMap.insert(std::make_pair(KeyCode::U, "U"));
	_enumStringMap.insert(std::make_pair(KeyCode::V, "V"));
	_enumStringMap.insert(std::make_pair(KeyCode::W, "W"));
	_enumStringMap.insert(std::make_pair(KeyCode::X, "X"));
	_enumStringMap.insert(std::make_pair(KeyCode::Y, "Y"));
	_enumStringMap.insert(std::make_pair(KeyCode::Z, "Z"));

	_enumStringMap.insert(std::make_pair(KeyCode::Num_0, "Num 0"));
	_enumStringMap.insert(std::make_pair(KeyCode::Num_1, "Num 1"));
	_enumStringMap.insert(std::make_pair(KeyCode::Num_2, "Num 2"));
	_enumStringMap.insert(std::make_pair(KeyCode::Num_3, "Num 3"));
	_enumStringMap.insert(std::make_pair(KeyCode::Num_4, "Num 4"));
	_enumStringMap.insert(std::make_pair(KeyCode::Num_5, "Num 5"));
	_enumStringMap.insert(std::make_pair(KeyCode::Num_6, "Num 6"));
	_enumStringMap.insert(std::make_pair(KeyCode::Num_7, "Num 7"));
	_enumStringMap.insert(std::make_pair(KeyCode::Num_8, "Num 8"));
	_enumStringMap.insert(std::make_pair(KeyCode::Num_9, "Num 9"));

	_enumStringMap.insert(std::make_pair(KeyCode::Numpad_0, "Numpad 0"));
	_enumStringMap.insert(std::make_pair(KeyCode::Numpad_1, "Numpad 1"));
	_enumStringMap.insert(std::make_pair(KeyCode::Numpad_2, "Numpad 2"));
	_enumStringMap.insert(std::make_pair(KeyCode::Numpad_3, "Numpad 3"));
	_enumStringMap.insert(std::make_pair(KeyCode::Numpad_4, "Numpad 4"));
	_enumStringMap.insert(std::make_pair(KeyCode::Numpad_5, "Numpad 5"));
	_enumStringMap.insert(std::make_pair(KeyCode::Numpad_6, "Numpad 6"));
	_enumStringMap.insert(std::make_pair(KeyCode::Numpad_7, "Numpad 7"));
	_enumStringMap.insert(std::make_pair(KeyCode::Numpad_8, "Numpad 8"));
	_enumStringMap.insert(std::make_pair(KeyCode::Numpad_9, "Numpad 9"));

	_enumStringMap.insert(std::make_pair(KeyCode::F1, "F1"));
	_enumStringMap.insert(std::make_pair(KeyCode::F2, "F2"));
	_enumStringMap.insert(std::make_pair(KeyCode::F3, "F3"));
	_enumStringMap.insert(std::make_pair(KeyCode::F4, "F4"));
	_enumStringMap.insert(std::make_pair(KeyCode::F5, "F5"));
	_enumStringMap.insert(std::make_pair(KeyCode::F6, "F6"));
	_enumStringMap.insert(std::make_pair(KeyCode::F7, "F7"));
	_enumStringMap.insert(std::make_pair(KeyCode::F8, "F8"));
	_enumStringMap.insert(std::make_pair(KeyCode::F9, "F9"));
	_enumStringMap.insert(std::make_pair(KeyCode::F10, "F10"));
	_enumStringMap.insert(std::make_pair(KeyCode::F11, "F11"));
	_enumStringMap.insert(std::make_pair(KeyCode::F12, "F12"));

	_enumStringMap.insert(std::make_pair(KeyCode::Escape, "Escape"));
	_enumStringMap.insert(std::make_pair(KeyCode::LCtrl, "L Ctrl"));
	_enumStringMap.insert(std::make_pair(KeyCode::LShift, "L Shift"));
	_enumStringMap.insert(std::make_pair(KeyCode::LAlt, "L ALt"));
	_enumStringMap.insert(std::make_pair(KeyCode::LSystem, "L System"));

	_enumStringMap.insert(std::make_pair(KeyCode::RCtrl, "R Ctrl"));
	_enumStringMap.insert(std::make_pair(KeyCode::RShift, "R Shift"));
	_enumStringMap.insert(std::make_pair(KeyCode::RAlt, "R Alt"));
	_enumStringMap.insert(std::make_pair(KeyCode::RSystem, "R System"));

	_enumStringMap.insert(std::make_pair(KeyCode::LBracket, "L Bracket"));
	_enumStringMap.insert(std::make_pair(KeyCode::RBracket, "R Bracket"));
	_enumStringMap.insert(std::make_pair(KeyCode::Semicolon, "Semicolon"));
	_enumStringMap.insert(std::make_pair(KeyCode::SemiColon, "Semicolon"));
	_enumStringMap.insert(std::make_pair(KeyCode::Comma, "Comma"));
	_enumStringMap.insert(std::make_pair(KeyCode::Period, "Period"));
	_enumStringMap.insert(std::make_pair(KeyCode::Quote, "Quote"));
	_enumStringMap.insert(std::make_pair(KeyCode::Slash, "Slash"));
	_enumStringMap.insert(std::make_pair(KeyCode::Backslash, "Backslash"));
	_enumStringMap.insert(std::make_pair(KeyCode::BackSlash, "Backslash"));

	_enumStringMap.insert(std::make_pair(KeyCode::Tilde, "Tilde"));
	_enumStringMap.insert(std::make_pair(KeyCode::Equal, "Equal"));
	_enumStringMap.insert(std::make_pair(KeyCode::Hyphen, "Hyphen"));
	_enumStringMap.insert(std::make_pair(KeyCode::Dash, "Hyphen"));

	_enumStringMap.insert(std::make_pair(KeyCode::Space, "Space"));
	_enumStringMap.insert(std::make_pair(KeyCode::Enter, "Enter"));
	_enumStringMap.insert(std::make_pair(KeyCode::Return, "Enter"));
	_enumStringMap.insert(std::make_pair(KeyCode::Backspace, "Backspace"));
	_enumStringMap.insert(std::make_pair(KeyCode::BackSpace, "Backspace"));
	_enumStringMap.insert(std::make_pair(KeyCode::Tab, "Tab"));

	_enumStringMap.insert(std::make_pair(KeyCode::PageUp, "PageUp"));
	_enumStringMap.insert(std::make_pair(KeyCode::PageDown, "PageDown"));
	_enumStringMap.insert(std::make_pair(KeyCode::Home, "Home"));
	_enumStringMap.insert(std::make_pair(KeyCode::End, "End"));
	_enumStringMap.insert(std::make_pair(KeyCode::Insert, "Insert"));
	_enumStringMap.insert(std::make_pair(KeyCode::Delete, "Delete"));

	_enumStringMap.insert(std::make_pair(KeyCode::Add, "Add"));
	_enumStringMap.insert(std::make_pair(KeyCode::Subtract, "Subtract"));
	_enumStringMap.insert(std::make_pair(KeyCode::Multiply, "Multiply"));
	_enumStringMap.insert(std::make_pair(KeyCode::Divide, "Divide"));

	_enumStringMap.insert(std::make_pair(KeyCode::Left, "Left"));
	_enumStringMap.insert(std::make_pair(KeyCode::Right, "Right"));
	_enumStringMap.insert(std::make_pair(KeyCode::Up, "Up"));
	_enumStringMap.insert(std::make_pair(KeyCode::Down, "Down"));

	_enumStringMap.insert(std::make_pair(KeyCode::Pause, "Pause"));
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
