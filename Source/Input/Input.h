#pragma once
#include <vector>
#include "KeyCode.h"


class Input
{
private :
	friend class RawInput;

	static Input* instance;
	static Input* Instance();

	std::vector<KeyCode> pressed;
	std::vector<KeyCode> hold;
	std::vector<KeyCode> released;
	
	static void KeyPressed(KeyCode key);
	static void KeyReleased(KeyCode key);

public :
	static void NextFrame();

	static bool GetKeyDown(KeyCode key);
	static bool GetKeyUp(KeyCode key);
	static bool GetKey(KeyCode key);

	static bool GetMouseButtonDown(KeyCode button);
	static bool GetMouseButtonUp(KeyCode button);
	static bool GetMouseButton(KeyCode button);

	static unsigned short GetMouseX();
	static unsigned short GetMouseY();
};