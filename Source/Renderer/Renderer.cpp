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

Renderer::Renderer()
{
	//Regular color based on resource amount
	//from maximum
	br_tile[0] = CreateSolidBrush(RGB(255, 0, 0));
	br_tile[1] = CreateSolidBrush(RGB(255, 100, 0));
	br_tile[2] = CreateSolidBrush(RGB(255, 255, 0));
	br_tile[3] = CreateSolidBrush(RGB(255, 255, 255));

	//high lighted color based on resource amount
	br_tile[4] = CreateSolidBrush(RGB(255, 100, 100));
	br_tile[5] = CreateSolidBrush(RGB(255, 160, 100));
	br_tile[6] = CreateSolidBrush(RGB(255, 255, 150));
	br_tile[7] = CreateSolidBrush(RGB(200, 200, 200));

	
	br_hidden = CreateSolidBrush(RGB(100, 100, 100));
	br_hidden_hl = CreateSolidBrush(RGB(150, 150, 150));
}

void Renderer::SetGrid(Grid* _grid)
{
	instance->grid = _grid;
}

void Renderer::Render(const PAINTSTRUCT& ps)
{
	if (!grid)
		return;
	unsigned short max_width = (grid->cell_width * grid->GetWidth());
	unsigned short max_height = (grid->cell_height * grid->GetHeight());
	RECT rect_tile = {
		(ps.rcPaint.left < 0)? 0 : ps.rcPaint.left, 
		(ps.rcPaint.top < 0)? 0 : ps.rcPaint.top, 
		(ps.rcPaint.right > max_width)? max_width : ps.rcPaint.right, 
		(ps.rcPaint.bottom > max_height)? max_height : ps.rcPaint.bottom};
	
	int numCell_x = (rect_tile.right - rect_tile.left) / grid->cell_width;
	int numCell_y = (rect_tile.bottom - rect_tile.top) / grid->cell_height;

	int start_x = rect_tile.left / grid->cell_width;
	int start_y = rect_tile.top / grid->cell_height;

	for (int i = start_x; i < start_x + numCell_x; i++)
	{
		for (int j = start_y; j < start_y + numCell_y; j++)
		{
			Cell* cur = grid->GetCell(i, j);

			if(cur->hidden)
				if(cur->selected)
					br_default = (HBRUSH)SelectObject(ps.hdc, br_hidden_hl);
				else
					br_default = (HBRUSH)SelectObject(ps.hdc, br_hidden);
			else
			{
				byte brush_index = cur->selected ? cur->resource_index + 4 : cur->resource_index;
				br_default = (HBRUSH)SelectObject(ps.hdc, br_tile[brush_index]);
			}

			Rectangle(ps.hdc, cur->x * 16, cur->y * 16, ((cur->x * 16) + cur->width), ((cur->y * 16) + cur->height));
		}
	}
	SelectObject(ps.hdc, br_default);
}