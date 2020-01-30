#pragma once
struct Cell
{
	unsigned short x;
	unsigned short y;
	unsigned short width;
	unsigned short height;

	unsigned int resource;
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

	inline unsigned short GetWidth() { return tile_width; }
	inline unsigned short GetHeight() { return tile_height; }
	inline Cell* GetCell(int x, int y) { return &(tile[x][y]); }
};