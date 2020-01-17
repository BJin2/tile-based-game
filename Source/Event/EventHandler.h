#pragma once
#include"../Debug/Debug.h"

class IEventHandler
{
private:
	template<class T>
	friend class EventHandler;
	virtual ~IEventHandler() = 0;
};

template <class T>
class EventHandler : public IEventHandler
{
private:
	void(*_handle)(const T* e);
	static void dummyHandle(const T* e)
	{
		Debug::Log("EventHandler.dummyHandler()");
	}

public:
	EventHandler()
	{
		_handle = dummyHandle;
	}
	void SetHandle(void(*passedPointer)(const T*)) { _handle = passedPointer; }
	void handle(T* e) { _handle(e); }
};