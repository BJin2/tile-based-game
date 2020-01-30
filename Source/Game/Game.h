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
	void Mix();
	void RoundGrid(void(*passed)(int i, int j, Game* g), int x, int y, int thickness);

public:
	const unsigned short max_num_maxResource = 6;
	inline Grid* GetGrid() { return grid; }
	void SetOwner(HWND _hWnd);
	void Start();
	void Update();
};