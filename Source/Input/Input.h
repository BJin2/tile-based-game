#pragma once
#include <vector>
#include "KeyCode.h"


class Input
{
private :
	std::vector<KeyCode> pressed;
	std::vector<KeyCode> hold;
	std::vector<KeyCode> released;

	static Input* instance;

public :
	static Input* Instance();
	static void NextFrame();
	static void KeyPressed(KeyCode key);
	static void KeyReleased(KeyCode key);

	static bool GetKeyDown(KeyCode key);
	static bool GetKeyUp(KeyCode key);
	static bool GetKey(KeyCode key);

	static bool GetMouseButtonDown(KeyCode button);
	static bool GetMouseButtonUp(KeyCode button);
	static bool GetMouseButton(KeyCode button);

	static unsigned short GetMouseX();
	static unsigned short GetMouseY();
};