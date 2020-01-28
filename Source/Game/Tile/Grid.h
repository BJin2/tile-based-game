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
	unsigned short tile_width;
	unsigned short tile_height;

public:
	Grid(unsigned short w, unsigned short h);
	~Grid();
	inline unsigned short GetWidth() { return tile_width; }
	inline unsigned short GetHeight() { return tile_height; }
	inline Cell* GetCell(int x, int y) { return &(tile[x][y]); }
};