#pragma once
#include <Windows.h>
#include <unordered_map>
#include "Event.h"
#include "EventHandler.h"

class EventMapper
{
private:
	HWND hWnd;
	std::unordered_map<EventType, EventHandler*> m_registeredHandler;

public:
	template<class T>
	void SetOnEvent(void(* passedPointer)(IEvent* e), EventType t);
	bool HandleEvent(EventType t, IEvent* data);
	void CleanMapper();
	inline HWND GetHWND() const { return hWnd; }
	inline void SetHWND(HWND _hWnd) { hWnd = _hWnd; }
};

