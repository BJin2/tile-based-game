#include"Grid.h"
#include "../Game.h"
#include <Windows.h>
#include <iostream>

Grid::Grid(unsigned short w, unsigned short h, Game* _owner)
{
	owner = _owner;

	tile_width = w;
	tile_height = h;

	tile = new Cell * [tile_width];
	for (int i = 0; i < tile_width; i++)
	{
		tile[i] = new Cell[tile_height];
		for (int j = 0; j < tile_height; j++)
		{
			tile[i][j].resource_index = 3;
			tile[i][j].x = i;
			tile[i][j].y = j;
			tile[i][j].width = cell_width;
			tile[i][j].height = cell_height;
			tile[i][j].hidden = true;
			tile[i][j].selected = false;
		}
	}
}

Grid::~Grid()
{
	for (int i = 0; i < tile_width; i++)
	{
		delete[] tile[i];
	}
	delete[] tile;
}