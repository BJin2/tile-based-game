#pragma once
#include <Windows.h>
#include "KeyCode.h"
struct InputEventData
{
	InputEventData() {}
	//Event from which window
	HWND hWnd = nullptr;
	//What kind of event
	EventType eventType = EventType::NO_TYPE;
};

class InputEvent
{
private :
	InputEventData* m_inputEventData;

public :
	inline EventType GetEventType()	const { return m_inputEventData->eventType; }
	inline HWND GetSource()			const { return m_inputEventData->hWnd; }

	inline void SetData(InputEventData* ie) { m_inputEventData = ie; }
};