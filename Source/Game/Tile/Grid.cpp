#include"Grid.h"

Grid::Grid(unsigned short w, unsigned short h)
{
	tile_width = w;
	tile_height = h;

	tile = new Cell * [tile_width];
	for (int i = 0; i < tile_width; i++)
	{
		tile[i] = new Cell[tile_height];
		for (int j = 0; j < tile_height; j++)
		{
			tile[i][j].resource = 10;
			tile[i][j].x = i;
			tile[i][j].y = j;
			tile[i][j].width = this->cell_width;
			tile[i][j].height = this->cell_height;
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
