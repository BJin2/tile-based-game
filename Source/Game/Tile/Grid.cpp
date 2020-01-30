#include"Grid.h"
#include <Windows.h>
#include <iostream>

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
			tile[i][j].resource_index = 3;
			//std::cout << tile[i][j].resource << std::endl;
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

int Grid::Extract(int x, int y, HWND hWnd)
{
	return 0;
}

void Grid::Scan(int x, int y, HWND hWnd)
{
	unsigned short start_x = (x <= 0 ? 0 : x - 1);
	unsigned short end_x = (x < tile_width-1 ? x + 1 : tile_width-1);
	unsigned short start_y = (y <= 0 ? 0 : y - 1);
	unsigned short end_y = (y < tile_height-1 ? y + 1 : tile_height-1);

	std::cout << start_x << ", " << end_x << std::endl;

	for (unsigned short i = start_x; i <= end_x; i++)
	{
		for (unsigned short j = start_y; j <= end_y; j++)
		{
			std::cout << "Scan" << std::endl;
			tile[i][j].hidden = false;
		}
	}
	RECT redrawArea1;
	SetRect(&redrawArea1,
		start_x * cell_width,
		start_y * cell_height,
		(end_x+1) * cell_width,
		(end_y+1) * cell_height);
	InvalidateRect(hWnd, &redrawArea1, true);
}
