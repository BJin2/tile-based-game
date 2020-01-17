#pragma once
#include <iostream>
#include <string>
#include "../Event/KeyCode.h"
#include "../Event/MouseEvent.h"

class Debug
{
public:
	static void Log(std::string msg);
	static std::string KeyCodeToString(KeyCode code);
};