#include "Game.h"
#include "../Debug/Debug.h"
#include "../Input/Input.h"

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
