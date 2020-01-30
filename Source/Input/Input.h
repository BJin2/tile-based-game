#pragma once
#include <vector>
#include "KeyCode.h"

struct Vector2
{
	short x;
	short y;
};

class Input
{
private :
	friend class RawInput;

	static Input* instance;
	static Input* Instance();

	std::vector<KeyCode> pressed;
	std::vector<KeyCode> hold;
	std::vector<KeyCode> released;

	Vector2* mousePosition;
	
	static void KeyPressed(KeyCode key);
	static void KeyReleased(KeyCode key);
	static void MousePressed(KeyCode button);
	static void MouseReleased(KeyCode button);
	static void MouseMoved(unsigned short x, unsigned short y);

public :
	static void NextFrame();

	static bool GetKeyDown(KeyCode key);
	static bool GetKeyUp(KeyCode key);
	static bool GetKey(KeyCode key);

	static bool GetMouseButtonDown(int button);
	static bool GetMouseButtonUp(int button);
	static bool GetMouseButton(int button);
	static const Vector2* GetMousePosition();
};