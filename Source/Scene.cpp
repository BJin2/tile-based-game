#include "Scene.h"

template<class T>
void Scene::SetOnEvent(void(*passedPointer)(const T* e), HandlerCode c)
{
	auto it = m_registeredEventHandler.find(c);
	if (it != m_registeredEventHandler.end())
	{
		static_cast<EventHandler<T>*>(it->second)->SetHandle(passedPointer);
	}
	else
	{
		EventHandler<T>* p = new EventHandler<T>();
		p->SetHandle(passedPointer);
		m_registeredEventHandler.insert(std::make_pair(c, p));
	}
}

bool Scene::HandleEvent(HandlerCode c, InputEvent* data)
{
	auto it = m_registeredEventHandler.find(c);
	if (it != m_registeredEventHandler.end())
	{
		static_cast<EventHandler<InputEvent>*>(it->second)->handle(data);
		return true;
	}
	else
	{
		std::cout << "NO HANDLER" << std::endl;
		return false;
	}
}

void Scene::SetOnKeyPressed(void(*passedPointer)(const KeyEvent* e))
{
	SetOnEvent<KeyEvent>(passedPointer, HandlerCode::OnKeyPressed);
}

void Scene::SetOnMousePressed(void(*passedPointer)(const MouseEvent* e))
{
	SetOnEvent<MouseEvent>(passedPointer, HandlerCode::OnMousePressed);
}

void Scene::cleanUp()
{
	for (auto it = m_registeredEventHandler.begin(); it != m_registeredEventHandler.end(); it++)
	{
		if (it->second != nullptr)
		{
			delete static_cast<EventHandler<InputEvent>*>(it->second);
		}
	}

	m_registeredEventHandler.clear();
}