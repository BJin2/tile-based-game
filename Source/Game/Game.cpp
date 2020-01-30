#include "Game.h"
#include "Tile/Grid.h"
#include "../Input/Input.h"
#include "../Renderer/Renderer.h"
#include "../Debug/Debug.h"

void Game::SetOwner(HWND _hWnd)
{
	hWnd = _hWnd;
}

void Game::Start()
{
	grid = new Grid(16, 16);
	Renderer::Instance()->SetGrid(grid);
}

void Game::Update()
{
	Vector2 mousePos = *(Input::GetMousePosition());
	int selected_x = -1;
	int selected_y = -1;

	//find selected cell
	for (int i = 0; i < grid->GetWidth(); i++)
	{
		for (int j = 0; j < grid->GetHeight(); j++)
		{
			
			if (grid->GetCell(i, j)->selected == true)
			{
				selected_x = i;
				selected_y = j;
				std::cout << selected_x << ", " << selected_y << std::endl;
				break;
			}
		}
		if (selected_x != -1 && selected_y != -1)
			break;
	}
	
	//if mouse is within tile
	if (mousePos.x > 0 && (mousePos.x < (grid->GetWidth() * grid->cell_width)) && 
		(mousePos.y > 0) && (mousePos.y < (grid->GetHeight() * grid->cell_height)))
	{
		//Calculate cell index based on mouse position
		int x = mousePos.x / grid->GetWidth();
		int y = mousePos.y / grid->GetHeight();
		
		//if it's different from previous selected cell index
		if (x != selected_x || y != selected_y)
		{
			//if there is previous selected cell
			if (selected_x != -1 && selected_y != -1)
			{
				//Set to not selected and redraw the cell
				Cell* selected_prev = grid->GetCell(selected_x, selected_y);
				selected_prev->selected = false;
				RECT redrawArea1;
				SetRect(&redrawArea1,
					selected_prev->x * selected_prev->width,
					selected_prev->y * selected_prev->height,
					(selected_prev->x * selected_prev->width) + selected_prev->width,
					(selected_prev->y * selected_prev->height) + selected_prev->height);
				InvalidateRect(hWnd, &redrawArea1, true);
			}
			
			//Set to selected and redraw the cell
			Cell* selected = grid->GetCell(x, y);
			selected->selected = true;

			RECT redrawArea2;
			SetRect(&redrawArea2, 
				selected->x * selected->width, 
				selected->y * selected->height, 
				(selected->x * selected->width) + selected->width,
				(selected->y * selected->height) + selected->height);
			InvalidateRect(hWnd, &redrawArea2, true);
		}
	}
}
