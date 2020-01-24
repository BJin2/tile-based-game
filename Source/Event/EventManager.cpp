#include "EventManager.h"

void EventManager::RegisterMapper(HWND hWnd, EventMapper* em)
{
	em->SetHWND(hWnd);
	m_registeredEventMapper.push_back(em);
}

void EventManager::RegisterEvent(EventType t, IEventData* data)
{
	
}

void EventManager::CleanMapper()
{
	for (auto const& mapper : m_registeredEventMapper)
	{
		mapper->CleanMapper();
	}
}
