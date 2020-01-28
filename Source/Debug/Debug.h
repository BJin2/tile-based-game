#if _DEBUG
#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "../Input/KeyCode.h"
#include "../Event/EventType.h"

class IEventData;
class KeyEventData;
class MouseEventData;

class Debug
{
public:
	static void Init();
	static void Log(std::string msg){std::cout << "Debug.Log : " << msg << std::endl;}
	static void Log(EventType type);
	static void Log(IEventData* _data);
	static void Log(KeyEventData _data);
	static void Log(MouseEventData _data);
	static std::string KeyCodeToString(KeyCode code);
private:
	static std::unordered_map<KeyCode, std::string> _enumStringMap;
};
#endif