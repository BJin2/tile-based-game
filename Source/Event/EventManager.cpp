#include "EventManager.h"

void EventManager::RegisterMapper(HWND hWnd, EventMapper* em)
{
	em->SetHWND(hWnd);
	m_registeredEventMapper.push_back(em);
}

void EventManager::RegisterEvent(EventType t, IEventData* data)
{
	//Create new temp event
	//temp goes to event mapper HandleEvent and then passed to EventHandler handle
	//freeing memory in handle, HandleEvent(failed case), this function(failed case)
	IEvent* temp = new IEvent();
	temp->SetData(data);

	//When proper data is not set
	if (temp->GetEventType() == EventType::NO_TYPE)
	{
		delete temp;
		return;
	}

	for (auto it = m_registeredEventMapper.begin(); it != m_registeredEventMapper.end(); it++)
	{
		if ((*it)->GetHWND() == data->hWnd)
		{
			(*it)->HandleEvent(t, temp);
			return;
		}
	}

	delete temp;
}

void EventManager::CleanMapper()
{
	for (auto const& mapper : m_registeredEventMapper)
	{
		mapper->CleanMapper();
	}
}
