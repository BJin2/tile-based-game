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
	InputEventData m_inputEventData;

public :
	virtual ~InputEvent() {}
	inline EventType GetEventType()	const { return m_inputEventData.eventType; }
	inline HWND GetSource()			const { return m_inputEventData.hWnd; }
	inline KeyCode GetKeyCode()		const { return m_inputEventData.mainKey; }
	inline bool isAltDown()			const { return m_inputEventData.alt; }
	inline bool isShiftDown()			const { return m_inputEventData.shift; }
	inline bool isCtrlDown()			const { return m_inputEventData.ctrl; }
	inline bool wasDown()				const { return m_inputEventData.wasDown; }

	inline void SetData(InputEventData ie) { m_inputEventData = ie; }
};