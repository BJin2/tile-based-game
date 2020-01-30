#pragma once
#include <Windows.h>

class Grid;

class Renderer
{
private :
	Renderer();
	static Renderer* instance;
	Grid* grid;

	HBRUSH br_tile[8];
	HBRUSH br_hidden;
	HBRUSH br_hidden_hl;
	HBRUSH br_default;

public :
	static Renderer* Instance();
	void SetGrid(Grid* _grid);
	void Render(const PAINTSTRUCT& ps);
};