#pragma once
#include <Windows.h>
#include "../Event/InputEvent.h"
#include "../Event/KeyEvent.h"
#include "../Event/MouseEvent.h"
#include "../Scene.h"

class InputMapper
{
private : 
	KeyEvent m_keyEvent;
	MouseEvent m_mouseEvent;
	std::vector<Scene*> m_sceneMap;
public :
	void RegisterKeyEvent(InputEventData data, HandlerCode c);
	void RegisterMouseEvent(MouseEventData mData, InputEventData data, HandlerCode c);
	void RegisterScene(HWND hWnd, Scene* scene);
	void SceneCleanUp();
};