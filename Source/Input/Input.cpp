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

bool Input::GetMouseButtonDown(KeyCode button)
{
	return GetKeyDown(button);
}

bool Input::GetMouseButtonUp(KeyCode button)
{
	return GetKeyUp(button);
}

bool Input::GetMouseButton(KeyCode button)
{
	return GetKey(button);
}
