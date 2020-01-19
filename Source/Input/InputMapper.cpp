#include "InputMapper.h"

void InputMapper::RegisterKeyEvent(InputEventData data, HandlerCode c)
{
	m_keyEvent.SetData(data);
	for (std::vector<Scene*>::iterator it = m_sceneMap.begin(); it != m_sceneMap.end(); i++)
	{
		if ((*it)->GetHwnd() == data.hWnd)
		{
			(*it)->HandleEvent(c, &m_keyEvent);
			return;
		}
	}
}

void InputMapper::RegisterMouseEvent(MouseEventData mData, InputEventData data, HandlerCode c)
{
	m_mouseEvent.SetData(data);
	m_mouseEvent.SetMouseEventData(mData);
	for (auto const& scene : m_sceneMap)
	{
		if (scene->GetHwnd() == data.hWnd)
		{
			scene->HandleEvent(c, &m_mouseEvent);
			return;
		}
	}
}

void InputMapper::RegisterScene(HWND hWnd, Scene* scene)
{
	scene->SetHwnd(hWnd);
	m_sceneMap.push_back(scene);
}

void InputMapper::SceneCleanUp()
{
	for (auto const& scene : m_sceneMap)
	{
		scene->cleanUp();
	}
}
