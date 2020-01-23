#pragma once
#include "Event.h"
struct KeyEventData : InputEventData
{
	KeyCode key = KeyCode::NO_CODE;
	bool down = false;
	bool up = false;
	bool hold = false;

	KeyEventData() : InputEventData() { eventType = EventType::KeyEvent; }
};

class KeyEvent : public InputEvent
{
private:
	KeyEventData m_keyEventData;
public:
	inline bool GetKeyDown(KeyCode key) { return (m_keyEventData.key == key) && m_keyEventData.down; }
	inline bool GetKeyUp(KeyCode key) { return (m_keyEventData.key == key) && m_keyEventData.up; }
	inline bool GetKey(KeyCode key) { return (m_keyEventData.key == key) && m_keyEventData.hold; }
};