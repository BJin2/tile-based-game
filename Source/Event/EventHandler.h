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
	static void DefaultHandle(const T* e)
	{
		Debug::Log("EventHandler.DefaultHandler");
	}

public:
	EventHandler()
	{
		_handle = DefaultHandle;
	}
	void SetHandle(void(*passedPointer)(const T*)) { _handle = passedPointer; }
	void handle(T* e) { _handle(e); }
};