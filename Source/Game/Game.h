#pragma once
#include <Windows.h>

class Grid;

class Game
{
private:
	HWND hWnd;
	Grid* grid;
public:
	void SetOwner(HWND _hWnd);
	void Start();
	void Update();
};