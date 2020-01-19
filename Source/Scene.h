#pragma once
#include <unordered_map>
#include "Event/EventHandler.h"
#include "Event/KeyCode.h"

class MouseEvent;
class KeyEvent;

class Scene
{
private:
	HWND m_hWnd;
	std::unordered_map < HandlerCode, IEventHandler*> m_registeredEventHandler;
	template <class T>
	void SetOnEvent(void(*passedPointer)(const T* e), HandlerCode c);
public:
	bool HandleEvent(HandlerCode c, InputEvent* data);
	const HWND GetHwnd() const { return m_hWnd; }
	void SetHwnd(HWND h) { m_hWnd = h; }
	void SetOnKeyPressed(void(*passedPointer)(const KeyEvent* e));
	void SetOnMousePressed(void(*passedPointer)(const MouseEvent* e));
	void cleanUp();
};