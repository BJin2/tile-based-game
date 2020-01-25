#pragma once
#include <vector>
#include "EventMapper.h"

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