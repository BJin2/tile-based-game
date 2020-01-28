#pragma once
#include <Windows.h>

class Grid;

class Renderer
{
private :
	static Renderer* instance;
	Grid* grid;

public :
	static Renderer* Instance();
	void SetGrid(Grid* _grid);
	void Render(const HDC& hdc);
};