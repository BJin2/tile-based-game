#pragma once
#include <iostream>
#include "../Debug/Debug.h"

class IEvent;

class EventHandler
{
private:
	void(*_handle)(const IEvent* e);
	static void DefaultHandle(const IEvent* e)
	{
		Debug::Log("EventHandler.DefaultHandler");
	}

public:
	EventHandler()
	{
		_handle = DefaultHandle;
	}
	void SetHandle(void(*passedPointer)(const IEvent*)) { _handle = passedPointer; }
	void handle(IEvent* e) { _handle(e); }
};