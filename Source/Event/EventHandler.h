#pragma once
#include "Event.h"
#ifdef _DEBUG
#include"../Debug/Debug.h"
#endif

class EventHandler
{
private:
	void(*_handle)(const IEvent* e);
	static void DefaultHandle(const IEvent* e)
	{
#ifdef _DEBUG
		Debug::Log("EventHandler.DefaultHandler");
#endif
	}

public:
	EventHandler()
	{
		_handle = DefaultHandle;
	}
	void SetHandle(void(*passedPointer)(const IEvent*)) { _handle = passedPointer; }
	void handle(IEvent* e) { _handle(e); delete e; }
};