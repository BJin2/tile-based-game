#pragma once
#ifdef _DEBUG
#include"../Debug/Debug.h"
#endif
class IEventHandler abstract
{
private:
	template<class T>
	friend class EventHandler;
	//virtual ~IEventHandler() = 0;
};

template <class T>
class EventHandler : public IEventHandler
{
private:
	void(*_handle)(const T* e);
	static void DefaultHandle(const T* e)
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
	void SetHandle(void(*passedPointer)(const T*)) { _handle = passedPointer; }
	void handle(T* e) { _handle(e); }
};

//IEventHandler::~IEventHandler() {}