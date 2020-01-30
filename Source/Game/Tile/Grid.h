#pragma once
#include<Windows.h>

struct Cell
{
	unsigned short x;
	unsigned short y;

	unsigned short width;
	unsigned short height;

	char resource_index;
	bool hidden;
	bool selected;
	char pad;
};

class Grid
{
private:
	Cell** tile;

	//size of the tile
	unsigned short tile_width;
	unsigned short tile_height;

public:
	Grid(unsigned short w, unsigned short h);
	~Grid();

	//actual pixel size of a cell
	const unsigned short cell_width = 16;
	const unsigned short cell_height = 16;

	const unsigned short resource_amount[4] = {1024, 512, 256, 64};

	void Mix();
	int Extract(int x, int y, HWND hWnd);
	void Scan(int x, int y, HWND hWnd);

	inline unsigned short GetWidth() { return tile_width; }
	inline unsigned short GetHeight() { return tile_height; }
	inline Cell* GetCell(int x, int y) { return &(tile[x][y]); }
};