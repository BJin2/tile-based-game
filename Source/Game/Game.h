#pragma once
#include <Windows.h>

class Grid;

class Game
{
private:
	HWND hWnd;
	Grid* grid;

	int resource;

	int Extract(int x, int y);
	void Scan(int x, int y);

public:
	void SetOwner(HWND _hWnd);
	void Start();
	void Update();
};