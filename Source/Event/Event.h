#pragma once
#include <Windows.h>
#include "EventType.h"
#include "../Input/KeyCode.h"

//Event data interface :
//Holding neccessary data for event handle
struct IEventData abstract
{
	//window that fired event
	HWND hWnd;
};

//Event interface:
//
class IEvent
{
protected:
	IEventData* m_eventData;

public:
	virtual EventType GetEventType() const { return EventType::NO_TYPE; }
	inline HWND GetSource() const { return m_eventData->hWnd; }
	inline void SetData(IEventData* ie) { m_eventData = ie; }
	inline IEventData* GetData() const { return m_eventData; }
};