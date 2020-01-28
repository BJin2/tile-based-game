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
	if (Input::GetMouseButton(KeyCode::Mouse0))
	{
		Debug::Log("Mouse 0 hold");
	}
	if (Input::GetKeyDown(KeyCode::A))
	{
		Debug::Log("A pressed");
	}
}
