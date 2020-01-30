#include "Game.h"
#include "Tile/Grid.h"
#include "../Input/Input.h"
#include "../Renderer/Renderer.h"
#include "../Debug/Debug.h"

void Game::Start()
{
	grid = new Grid(16, 16);
	Renderer::Instance()->SetGrid(grid);
}

void Game::Update()
{
	if (Input::GetMouseButtonDown(2))
	{
		Debug::Log("M");
		//grid->GetCell(2, 2)->resource = 30;
	}
	if (Input::GetMouseButtonDown(0))
	{
		std::cout << Input::GetMousePosition()->x << ", " << Input::GetMousePosition()->y << std::endl;
	}
}
