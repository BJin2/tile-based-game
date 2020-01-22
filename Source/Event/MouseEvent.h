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
private:
	MouseEventData m_mouseEventData;
public:
	inline unsigned short GetScreenX() const { return m_mouseEventData.screenX; }
	inline unsigned short GetScreenY() const { return m_mouseEventData.screenY; }
	inline unsigned short GetWindowX() const { return m_mouseEventData.windowX; }
	inline unsigned short GetWindowY() const { return m_mouseEventData.windowY; }

	inline bool IsMiddleDown() const { return m_mouseEventData.isMiddleDown; }
	inline bool IsLeftDown() const { return m_mouseEventData.isLeftDown; }
	inline bool IsRightDown() const { return m_mouseEventData.isRightDown; }

	inline KeyCode GetMouseButtonCode() const { return m_mouseEventData.mouseButtonCode; }

	inline void SetMouseEventData(MouseEventData me) { m_mouseEventData = me; }
};