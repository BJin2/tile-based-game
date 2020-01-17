#pragma once
#include "InputEvent.h"

struct MouseEventData
{
	unsigned short screenX = 0;
	unsigned short screenY = 0;
	unsigned short windowX = 0;
	unsigned short windowY = 0;

	bool isMiddleDown = false;
	bool isLeftDown = false;
	bool isRightDown = false;
	KeyCode mouseButtonCode = KeyCode::NO_CODE;
	MouseEventData() {}
};

class MouseEvent : public InputEvent
{
	MouseEventData _mouseEventData;
};