#pragma once
#include <Windows.h>
#include <vector>
#include "EventType.h"

class EventMapper;
class IEvent;
class IEventData;

class EventManager
{
private:
	std::vector<EventMapper*> m_registeredEventMapper;
	static EventManager* instance;
	IEvent* mainEvent;

public:
	static EventManager* Instance();
	void RegisterMapper(HWND hWnd, EventMapper* em);
	void RegisterEvent(EventType t, IEventData* data);
	void CleanMapper();
};