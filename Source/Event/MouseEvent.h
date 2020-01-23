#pragma once
#include <unordered_map>
#include "Event.h"
#include "../Input/KeyCode.h"

struct MouseEventData : IEventData
{
	KeyCode button = KeyCode::NO_CODE;

	unsigned short screenX = 0;
	unsigned short screenY = 0;
	unsigned short windowX = 0;
	unsigned short windowY = 0;
	
	std::unordered_map<KeyCode, bool> down;
	std::unordered_map<KeyCode, bool> up;
	std::unordered_map<KeyCode, bool> hold;
	
	MouseEventData()
	{
		down.insert(std::make_pair(KeyCode::Mouse0, false));
		down.insert(std::make_pair(KeyCode::Mouse1, false));
		down.insert(std::make_pair(KeyCode::Mouse2, false));

		up.insert(std::make_pair(KeyCode::Mouse0, false));
		up.insert(std::make_pair(KeyCode::Mouse1, false));
		up.insert(std::make_pair(KeyCode::Mouse2, false));

		hold.insert(std::make_pair(KeyCode::Mouse0, false));
		hold.insert(std::make_pair(KeyCode::Mouse1, false));
		hold.insert(std::make_pair(KeyCode::Mouse2, false));
	}
};

class MouseEvent : public IEvent
{
private:
	MouseEventData m_mouseEventData;
	
public:
	static const EventType Event;

	virtual const EventType GetEventType() const { return Event; }

	inline unsigned short GetScreenX() const { return m_mouseEventData.screenX; }
	inline unsigned short GetScreenY() const { return m_mouseEventData.screenY; }
	inline unsigned short GetWindowX() const { return m_mouseEventData.windowX; }
	inline unsigned short GetWindowY() const { return m_mouseEventData.windowY; }

	inline bool GetMouseButtonDown(KeyCode button) { return m_mouseEventData.down[button]; }
	inline bool GetMouseButtonUp(KeyCode button) { return m_mouseEventData.up[button]; }
	inline bool GetMouseButton(KeyCode button) { return m_mouseEventData.hold[button]; }
};