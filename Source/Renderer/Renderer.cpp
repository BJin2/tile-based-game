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

void Renderer::Render(const HDC& hdc)
{
	for (int i = 0; i < grid->GetWidth(); i++)
	{
		for (int j = 0; j < grid->GetHeight(); j++)
		{
			std::cout << i << ", " << j << std::endl;
			Cell* cur = grid->GetCell(i, j);
			/*for (int x = cur->x; x < (cur->x + cur->width); x++)
			{
				for (int y = cur->y; y < (cur->y + cur->height); y++)
				{
					COLORREF c;
					if (cur->resource > 10)
					{
						c = RGB(255, 0, 0);
					}
					else
					{
						c = RGB(0, 255, 0);
					}
					SetPixel(hdc, x + (16*i), y + (16*j), c);
				}
			}*/
			Rectangle(hdc, cur->x * 16, cur->y * 16, ((cur->x * 16) + cur->width), ((cur->y*16) + cur->height));
		}
	}
	//SetPixel(hdc, 10, 10, RGB(0, 255, 0));
	//MoveToEx(hdc, 50, 50, NULL);
	//LineTo(hdc, 300, 90);
	//Rectangle(hdc, 50, 100, 200, 180);
}