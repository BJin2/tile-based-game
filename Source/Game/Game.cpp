#include "Game.h"
#include "../Debug/Debug.h"
#include "../Input/Input.h"

void Game::Update()
{
	if (Input::GetMouseButtonUp(KeyCode::Mouse0))
	{
		Debug::Log("UP");
	}
}
