#pragma once
#include <vector>
#include "EventMapper.h"

class EventManager
{
private:
	std::vector<EventMapper*> m_registeredEventMapper;

public:
	void RegisterMapper(HWND hWnd, EventMapper* em);
	
};

