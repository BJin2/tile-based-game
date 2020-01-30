#include "Input.h"
#include "../Debug/Debug.h"

Input* Input::instance;
Input* Input::Instance()
{
	if (instance)
		return instance;
	else
		return instance = new Input();
}

void Input::NextFrame()
{
	Input::Instance();
	
	for (auto it = instance->pressed.begin(); it != instance->pressed.end(); it++)
	{
		instance->hold.push_back(*it);
	}
	instance->pressed.clear();
	instance->released.clear();

	//for (auto it = instance->hold.begin(); it != instance->hold.end(); it++)
	//{
	//	Debug::Log(Debug::KeyCodeToString(*it));
	//}
}

void Input::KeyPressed(KeyCode key)
{
	int i = 0;
	for (auto it = instance->hold.begin(); it != instance->hold.end(); it++, i++)
	{
		if (key == *it)
		{
			return;
		}
	}
	instance->pressed.push_back(key);
}
void Input::KeyReleased(KeyCode key)
{
	//Debug::Log("Release");
	int i = 0;
	for (auto it = instance->pressed.begin(); it != instance->pressed.end(); it++, i++)
	{
		if (key == *it)
		{
			instance->released.push_back(key);
			instance->pressed.erase(instance->pressed.begin() + i);
			return;
		}
	}

	i = 0;
	for (auto it = instance->hold.begin(); it != instance->hold.end(); it++, i++)
	{
		if (key == *it)
		{
			instance->released.push_back(key);
			instance->hold.erase(instance->hold.begin() + i);
			return;
		}
	}
}

void Input::MousePressed(KeyCode button)
{
	KeyPressed(button);
	
}
void Input::MouseReleased(KeyCode button)
{
	KeyReleased(button);
}
void Input::MouseMoved(unsigned short x, unsigned short y)
{
	if (!instance->mousePosition)
	{
		instance->mousePosition = new Vector2();
	}
	instance->mousePosition->x = x;
	instance->mousePosition->y = y;
}

bool Input::GetKeyDown(KeyCode key)
{
	for (auto it = instance->pressed.begin(); it != instance->pressed.end(); it++)
	{
		if (key == *it)
			return true;
	}
	return false;
}

bool Input::GetKeyUp(KeyCode key)
{
	for (auto it = instance->released.begin(); it != instance->released.end(); it++)
	{
		if (key == *it)
			return true;
	}
	return false;
}

bool Input::GetKey(KeyCode key)
{
	for (auto it = instance->hold.begin(); it != instance->hold.end(); it++)
	{
		if (key == *it)
			return true;
	}
	return false;
}

bool Input::GetMouseButtonDown(int button)
{
	KeyCode b;
	switch (button)
	{
	case 0:
		b = KeyCode::Mouse0;
		break;
	case 1:
		b = KeyCode::Mouse1;
		break;
	case 2:
		b = KeyCode::Mouse2;
		break;
	default:
		b = KeyCode::NO_CODE;
		break;
	}
	
	return GetKeyDown(b);
}

bool Input::GetMouseButtonUp(int button)
{
	KeyCode b;
	switch (button)
	{
	case 0:
		b = KeyCode::Mouse0;
		break;
	case 1:
		b = KeyCode::Mouse1;
		break;
	case 2:
		b = KeyCode::Mouse2;
		break;
	default:
		b = KeyCode::NO_CODE;
		break;
	}
	return GetKeyUp(b);
}

bool Input::GetMouseButton(int button)
{
	KeyCode b;
	switch (button)
	{
	case 0:
		b = KeyCode::Mouse0;
		break;
	case 1:
		b = KeyCode::Mouse1;
		break;
	case 2:
		b = KeyCode::Mouse2;
		break;
	default:
		b = KeyCode::NO_CODE;
		break;
	}
	return GetKey(b);
}

const Vector2* Input::GetMousePosition()
{
	if (!instance->mousePosition)
	{
		instance->mousePosition = new Vector2();
	}
	return instance->mousePosition;
}
