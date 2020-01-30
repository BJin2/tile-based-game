#include "Renderer.h"
#include "../Game/Tile/Grid.h"

#include "../Debug/Debug.h"

Renderer* Renderer::instance;
Renderer* Renderer::Instance()
{
	if (instance)
		return instance;
	else
		return instance = new Renderer();
}

void Renderer::SetGrid(Grid* _grid)
{
	instance->grid = _grid;
}

void Renderer::Render(const PAINTSTRUCT& ps)
{
	Debug::Log("Rendering");

	HBRUSH br_red = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH br_green = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH br_default = (HBRUSH)SelectObject(ps.hdc, br_red);

	int numCell_x = (ps.rcPaint.right - ps.rcPaint.left) / grid->cell_width;
	int numCell_y = (ps.rcPaint.bottom - ps.rcPaint.top) / grid->cell_height;

	int start_x = ps.rcPaint.left / grid->cell_width;
	int start_y = ps.rcPaint.top / grid->cell_height;

	for (int i = start_x; i < start_x + numCell_x; i++)
	{
		for (int j = start_y; j < start_y + numCell_y; j++)
		{
			Cell* cur = grid->GetCell(i, j);
			if (cur->resource > 10)
			{
				SelectObject(ps.hdc, br_green);
			}
			else
			{
				SelectObject(ps.hdc, br_red);
			}
			Rectangle(ps.hdc, cur->x * 16, cur->y * 16, ((cur->x * 16) + cur->width), ((cur->y * 16) + cur->height));
		}
	}
	SelectObject(ps.hdc, br_default);
	DeleteObject(br_red);
	DeleteObject(br_green);
}