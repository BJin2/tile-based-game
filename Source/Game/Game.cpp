#include "Game.h"
#include "../Renderer/Renderer.h"
#include "Tile/Grid.h"
#include "../Debug/Debug.h"
#include "../Input/Input.h"

void Game::Start()
{
	grid = new Grid(16, 16);
	Renderer::Instance()->SetGrid(grid);
}

void Game::Update()
{
	if (Input::GetMouseButtonDown(KeyCode::Mouse0))
	{
		//grid->GetCell(2, 2)->resource = 30;
	}
	if (Input::GetKeyDown(KeyCode::A))
	{
		Debug::Log("A pressed");
	}
}
