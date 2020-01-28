#include "Debug.h"
#include "../Event/KeyEvent.h"
#include "../Event/MouseEvent.h"

std::unordered_map<KeyCode, std::string> Debug::_enumStringMap;
void Debug::Init()
{
	static bool initialized = false;
	if (initialized)
		return;
	initialized = true;

	_enumStringMap.insert(std::make_pair(KeyCode::NO_CODE, "NO_CODE"));
	_enumStringMap.insert(std::make_pair(KeyCode::Mouse0, "Mouse0"));
	_enumStringMap.insert(std::make_pair(KeyCode::Mouse1, "Mouse1"));
	_enumStringMap.insert(std::make_pair(KeyCode::Mouse2, "Mouse2"));

	_enumStringMap.insert(std::make_pair(KeyCode::Backspace, "Backspace"));
	_enumStringMap.insert(std::make_pair(KeyCode::Delete, "Delete"));
	_enumStringMap.insert(std::make_pair(KeyCode::Tab, "Tab"));
	_enumStringMap.insert(std::make_pair(KeyCode::Return, "Return"));

	_enumStringMap.insert(std::make_pair(KeyCode::Pause, "Pause"));
	_enumStringMap.insert(std::make_pair(KeyCode::Escape, "Escape"));
	_enumStringMap.insert(std::make_pair(KeyCode::Space, "Space"));

	_enumStringMap.insert(std::make_pair(KeyCode::CapsLock, "CapsLock"));
	_enumStringMap.insert(std::make_pair(KeyCode::Shift, "Shift"));
	_enumStringMap.insert(std::make_pair(KeyCode::Ctrl, "Ctrl"));

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

	_enumStringMap.insert(std::make_pair(KeyCode::Keypad0, "Keypad0"));
	_enumStringMap.insert(std::make_pair(KeyCode::Keypad1, "Keypad1"));
	_enumStringMap.insert(std::make_pair(KeyCode::Keypad2, "Keypad2"));
	_enumStringMap.insert(std::make_pair(KeyCode::Keypad3, "Keypad3"));
	_enumStringMap.insert(std::make_pair(KeyCode::Keypad4, "Keypad4"));
	_enumStringMap.insert(std::make_pair(KeyCode::Keypad5, "Keypad5"));
	_enumStringMap.insert(std::make_pair(KeyCode::Keypad6, "Keypad6"));
	_enumStringMap.insert(std::make_pair(KeyCode::Keypad7, "Keypad7"));
	_enumStringMap.insert(std::make_pair(KeyCode::Keypad8, "Keypad8"));
	_enumStringMap.insert(std::make_pair(KeyCode::Keypad9, "Keypad9"));

	_enumStringMap.insert(std::make_pair(KeyCode::Alpha0, "Alpha0"));
	_enumStringMap.insert(std::make_pair(KeyCode::Alpha1, "Alpha1"));
	_enumStringMap.insert(std::make_pair(KeyCode::Alpha2, "Alpha2"));
	_enumStringMap.insert(std::make_pair(KeyCode::Alpha3, "Alpha3"));
	_enumStringMap.insert(std::make_pair(KeyCode::Alpha4, "Alpha4"));
	_enumStringMap.insert(std::make_pair(KeyCode::Alpha5, "Alpha5"));
	_enumStringMap.insert(std::make_pair(KeyCode::Alpha6, "Alpha6"));
	_enumStringMap.insert(std::make_pair(KeyCode::Alpha7, "Alpha7"));
	_enumStringMap.insert(std::make_pair(KeyCode::Alpha8, "Alpha8"));
	_enumStringMap.insert(std::make_pair(KeyCode::Alpha9, "Alpha9"));
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

	_enumStringMap.insert(std::make_pair(KeyCode::Backspace, "Backspace"));
	_enumStringMap.insert(std::make_pair(KeyCode::Delete, "Delete"));
	_enumStringMap.insert(std::make_pair(KeyCode::Tab, "Tab"));
	_enumStringMap.insert(std::make_pair(KeyCode::Return, "Return"));
	_enumStringMap.insert(std::make_pair(KeyCode::Pause, "Pause"));
	_enumStringMap.insert(std::make_pair(KeyCode::Escape, "Escape"));
	_enumStringMap.insert(std::make_pair(KeyCode::Space, "Space"));
	_enumStringMap.insert(std::make_pair(KeyCode::CapsLock, "CapsLock"));
	_enumStringMap.insert(std::make_pair(KeyCode::NumLock, "NumLock"));
	_enumStringMap.insert(std::make_pair(KeyCode::ScrollLock, "ScrollLock"));
	_enumStringMap.insert(std::make_pair(KeyCode::KeypadPeriod, "KeypadPeriod"));
	_enumStringMap.insert(std::make_pair(KeyCode::KeypadDivide, "KeypadDivide"));
	_enumStringMap.insert(std::make_pair(KeyCode::KeypadMultiply, "KeypadMultiply"));
	_enumStringMap.insert(std::make_pair(KeyCode::KeypadMinus, "KeypadMinus"));
	_enumStringMap.insert(std::make_pair(KeyCode::KeypadPlus, "KeypadPlus"));
	_enumStringMap.insert(std::make_pair(KeyCode::KeypadEnter, "KeypadEnter"));
	_enumStringMap.insert(std::make_pair(KeyCode::UpArrow, "UpArrow"));
	_enumStringMap.insert(std::make_pair(KeyCode::DownArrow, "DownArrow"));
	_enumStringMap.insert(std::make_pair(KeyCode::RightArrow, "RightArrow"));
	_enumStringMap.insert(std::make_pair(KeyCode::LeftArrow, "LeftArrow"));
	_enumStringMap.insert(std::make_pair(KeyCode::Insert, "Insert"));
	_enumStringMap.insert(std::make_pair(KeyCode::Home, "Home"));
	_enumStringMap.insert(std::make_pair(KeyCode::End, "End"));
	_enumStringMap.insert(std::make_pair(KeyCode::PageUp, "PageUp"));
	_enumStringMap.insert(std::make_pair(KeyCode::PageDown, "PageDown"));
	_enumStringMap.insert(std::make_pair(KeyCode::PrintScreen, "PrintScreen"));
	_enumStringMap.insert(std::make_pair(KeyCode::Equals, "Equals"));
	_enumStringMap.insert(std::make_pair(KeyCode::Comma, "Comma"));
	_enumStringMap.insert(std::make_pair(KeyCode::Minus, "Minus"));
	_enumStringMap.insert(std::make_pair(KeyCode::Period, "Period"));
	_enumStringMap.insert(std::make_pair(KeyCode::ForwardSlash, "ForwardSlash"));
	_enumStringMap.insert(std::make_pair(KeyCode::BackSlash, "BackSlash"));
	_enumStringMap.insert(std::make_pair(KeyCode::Colon, "Colon"));
	_enumStringMap.insert(std::make_pair(KeyCode::LeftBracket, "LeftBracket"));
	_enumStringMap.insert(std::make_pair(KeyCode::RightBracket, "RightBracket"));
	_enumStringMap.insert(std::make_pair(KeyCode::Quote, "Quote"));
	_enumStringMap.insert(std::make_pair(KeyCode::BackQuote, "BackQuote"));
}

void Debug::Log(EventType type)
{
	if (type == EventType::KeyEvent)
		Log("KeyEvent");
	else if (type == EventType::MouseEvent)
		Log("MouseEvent");
	else
		Log("NO_TYPE");
}

void Debug::Log(IEventData* _data)
{
	TCHAR title[40];
	GetWindowText(_data->hWnd, title, sizeof(title));
	std::cout << "==== Input Data ====" << std::endl;
	std::wcout << "Calling Window : " << title << std::endl;
}

void Debug::Log(KeyEventData _data)
{
	Log(&_data);
	std::cout << "==== Key Data ====" << std::endl;
	std::cout << "Key : " << KeyCodeToString(_data.key) << std::endl;
	std::cout << "Is Key Down : " << _data.down << std::endl;
	std::cout << "Is Key Up : " << _data.up << std::endl;
	std::cout << "Is Key Hold : " << _data.hold << std::endl;
}

void Debug::Log(MouseEventData _data)
{
	Log(&_data);
	std::cout << "==== Mouse Data ====" << std::endl;
	std::cout << "Screen X : " << _data.screenX << std::endl;
	std::cout << "Screen Y : " << _data.screenY << std::endl;
	std::cout << "Window X : " << _data.windowX << std::endl;
	std::cout << "Window Y : " << _data.windowY << std::endl;

	std::cout << "MouseButton : " << KeyCodeToString(_data.button) << std::endl;
	//std::cout << "Is Button Down : " << _data.down[_data.button] << std::endl;
	//std::cout << "Is Button Up : " << _data.up[_data.button] << std::endl;
	//std::cout << "Is Button Hold : " << _data.hold[_data.button] << std::endl;
}

std::string Debug::KeyCodeToString(KeyCode code)
{
	auto it = _enumStringMap.find(code);
	if (it == _enumStringMap.end())
	{
		return "Debug.NO_KEY";
	}
	else
	{
		return it->second;
	}
}
