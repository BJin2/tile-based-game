#pragma once
#include <Windows.h>
#include "KeyCode.h"
struct InputEventData
{
	HWND hWnd = nullptr;
	EventType eventType = EventType::NO_TYPE;
	KeyCode mainKey = KeyCode::NO_CODE;
	bool shift = false;
	bool ctrl = false;
	bool alt = false;
	bool wasDown = false;
public:
	InputEventData() {};
};

class InputEvent
{
private :
	InputEventData _inputEventData;

public :
	virtual ~InputEvent() {}
};