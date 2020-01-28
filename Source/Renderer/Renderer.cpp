#include "Renderer.h"
#include "../Game/Tile/Grid.h"

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

void Renderer::Render(const HDC& hdc)
{
	for (int i = 0; i < grid->GetWidth(); i++)
	{
		for (int j = 0; j < grid->GetHeight(); j++)
		{
			Cell* cur = grid->GetCell(i, j);
			for (int x = cur->x; x < (cur->x + cur->width); x++)
			{
				for (int y = cur->y; y < (cur->y + cur->height); y++)
				{
					SetPixel(hdc, x, y, RGB(255, 0, 0));
				}
			}
			Rectangle(hdc, cur->x, cur->y, (cur->x + cur->width), (cur->y + cur->height));
		}
	}
	SetPixel(hdc, 10, 10, RGB(0, 255, 0));
	MoveToEx(hdc, 50, 50, NULL);
	LineTo(hdc, 300, 90);
	Rectangle(hdc, 50, 100, 200, 180);
}