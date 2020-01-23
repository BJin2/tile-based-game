#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "../Event/KeyEvent.h"
#include "../Event/MouseEvent.h"

class Debug
{
public:
	static void Init();
	static void Log(std::string msg){std::cout << "Debug.Log : " << msg << std::endl;}
	static void Log(InputEventData* _data);
	static void Log(KeyEventData _data);
	static void Log(MouseEventData _data);
	static std::string KeyCodeToString(KeyCode code);
private:
	static std::unordered_map<KeyCode, std::string> _enumStringMap;
};