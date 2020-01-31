#include <time.h>
#include <tchar.h>  
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
	//Create tile
	grid = new Grid(16, 16, this);
	Mix();

	//Init
	srand(time(NULL));
	scanMode = true;
	resource = 0;
	max_scan = 6;
	max_extract = 3;

	text_chance = new TCHAR[1024];
	text_resource = new TCHAR[1024];
	text_message = new TCHAR[1024];

	//Init renderer properties
	Renderer::Instance()->SetGrid(grid);
	UpdateText();

	CheckRadioButton(hWnd, COMMAND_SCAN_MODE, COMMAND_EXTRACT_MODE, COMMAND_SCAN_MODE);
	InvalidateRect(hWnd, NULL, true);
}

void Game::Update()
{
	if (Input::GetKeyDown(KeyCode::M))
	{
		scanMode = !scanMode;
	}

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
		
		if (Input::GetMouseButtonDown(0))
		{
			if (scanMode)
				Scan(x, y);
			else
				resource += Extract(x, y);
			UpdateText();
		}

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

	//Check game end condition at the end of the game loop
	if (max_extract == 0)
	{
		LPWSTR temp = new TCHAR[1024];
		wsprintf(temp, TEXT("You got : %d\nThank you for playing.\nDo you want to play again?"), resource);
		if (MessageBox(hWnd, temp, TEXT("Game Finished"), MB_YESNO) == IDYES)
		{
			Start();
		}
		else
		{
			PostQuitMessage(0);
		}
	}
}

void Game::ScanMode()
{
	scanMode = true;
	UpdateText();
}

void Game::ExtractMode()
{
	scanMode = false;
	UpdateText();
}


#pragma region Grid
int Game::Extract(int x, int y)
{
	if (max_extract == 0)
	{
		MessageBeep(MB_OK);
		return 0;
	}

	int r = grid->resource_amount[grid->GetCell(x, y)->resource_index];
	grid->GetCell(x, y)->resource_index = 3;

	RoundGrid([](int i, int j, Game* g)->void
		{
			Cell* cell = g->GetGrid()->GetCell(i, j);
			if (cell->resource_index < 3)
				cell->resource_index += 1;
		}
	, x, y, 2);
	//number of scan should not change when extracting
	//adding 1 before scanning in extract mode so that total number does not change
	max_scan++;
	Scan(x, y);
	max_extract--;
	return r;
}

void Game::Scan(int x, int y)
{
	if (max_scan == 0)
	{
		MessageBeep(MB_OK);
		return;
	}
	RoundGrid([](int i, int j, Game* g)->void {g->GetGrid()->GetCell(i, j)->hidden = false; }, x, y, 1);
	max_scan--;
}

void Game::Mix()
{
	for (int i = 0; i < max_num_maxResource; i++)
	{
		int random_x = (rand() % grid->GetWidth());
		int random_y = (rand() % grid->GetHeight());
		RoundGrid([](int i, int j, Game* g)
			{
				if (g->GetGrid()->GetCell(i, j)->resource_index > 2)
					g->GetGrid()->GetCell(i, j)->resource_index = 2;
			}, random_x, random_y, 2);
		RoundGrid([](int i, int j, Game* g)
			{
				if (g->GetGrid()->GetCell(i, j)->resource_index > 1)
					g->GetGrid()->GetCell(i, j)->resource_index = 1;
			}, random_x, random_y, 1);
		grid->GetCell(random_x, random_y)->resource_index = 0;
	}
}

void Game::RoundGrid(void(*passed)(int i, int j, Game* g), int x, int y, int thickness)
{
	unsigned short start_x = (x - thickness < 0 ? 0 : x - thickness);
	unsigned short end_x = (x + thickness >= grid->GetWidth() ? grid->GetWidth() - 1 : x + thickness);
	unsigned short start_y = (y - thickness < 0 ? 0 : y - thickness);
	unsigned short end_y = (y + thickness >= grid->GetHeight() ? grid->GetHeight() - 1 : y + thickness);

	for (unsigned short i = start_x; i <= end_x; i++)
	{
		for (unsigned short j = start_y; j <= end_y; j++)
		{
			passed(i, j, this);
		}
	}
	RECT redrawArea;
	SetRect(&redrawArea,
		start_x * grid->GetWidth(),
		start_y * grid->GetHeight(),
		(end_x + 1) * grid->GetWidth(),
		(end_y + 1) * grid->GetHeight());
	InvalidateRect(hWnd, &redrawArea, true);
}
#pragma endregion

#pragma region Text
void Game::UpdateText()
{
	wsprintf(text_resource, TEXT("Rsrc:%d"), resource);
	if (scanMode)
	{
		wsprintf(text_chance, TEXT("Scan:%d"), max_scan);
		if (max_scan > 0)
			wsprintf(text_message, TEXT("Click on a cell and scan the area."));
		else
			wsprintf(text_message, TEXT("You cannot scan any more."));
	}
	else
	{
		wsprintf(text_chance, TEXT("Extract:%d"), max_extract);
		if (max_extract > 0)
			wsprintf(text_message, TEXT("Click on a cell and get the resource."));
		else
			wsprintf(text_message, TEXT("You cannot extract any more."));
	}

	InvalidateRect(hWnd, &rect_text, true);
}

LPWSTR Game::GetChanceText()
{
	return text_chance;
}
int Game::GetChanceTextLength()
{
	return lstrlen(text_chance);
}

LPWSTR Game::GetResourceText()
{
	return text_resource;
}
int Game::GetResourceTextLength()
{
	return lstrlen(text_resource);
}

LPWSTR Game::GetMessageText()
{
	return text_message;
}
int Game::GetMessageTextLength()
{
	return lstrlen(text_message);
}
#pragma endregion

