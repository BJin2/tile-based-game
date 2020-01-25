#include "EventManager.h"
EventManager* EventManager::instance;


EventManager* EventManager::Instance()
{
	if (instance)
		return instance;
	else
		return instance = new EventManager();
}

void EventManager::RegisterMapper(HWND hWnd, EventMapper* em)
{
	em->SetHWND(hWnd);
	m_registeredEventMapper.push_back(em);
}

void EventManager::RegisterEvent(EventType t, IEventData* data)
{
	IEvent* temp = new IEvent();
	temp->SetData(data);

	for (auto it = m_registeredEventMapper.begin(); it != m_registeredEventMapper.end(); it++)
	{
		if ((*it)->GetHWND() == data->hWnd)
		{
			(*it)->HandleEvent(t, temp);
			delete temp;
			return;
		}
	}
}

void EventManager::CleanMapper()
{
	for (auto const& mapper : m_registeredEventMapper)
	{
		mapper->CleanMapper();
	}
}
