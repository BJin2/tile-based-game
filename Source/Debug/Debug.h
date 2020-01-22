#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "../Event/KeyCode.h"
#include "../Event/MouseEvent.h"

class Debug
{
public:
	static void Init();
	static void Log(std::string msg);
	static void Log(InputEventData _data);
	static void Log(MouseEventData _mData);
	static std::string KeyCodeToString(KeyCode code);
private:
	static std::unordered_map<KeyCode, std::string> _enumStringMap;
};