#pragma once
#include <Windows.h>
#include "EventType.h"

class IEventData
{
public:
	virtual ~IEventData() = 0;
	//window that fired event
	HWND hWnd = nullptr;
};

IEventData::~IEventData() {}

class IEvent
{
private:
	IEventData* m_eventData;

public:
	virtual const EventType GetEventType() const = 0;
	inline HWND GetSource() const { return m_eventData->hWnd; }

	inline void SetData(IEventData* ie) { m_eventData = ie; }
};