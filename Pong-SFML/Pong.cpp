#include <SFML\Graphics.hpp>

#include "Game.h"
#include "Paddle.h"

int main()
{
	Paddle player;
	EntMgr.Add(&player);

	while (Game::GetWindow()->isOpen())
	{
		Game::HandleEvents();

		Game::Draw();
	}

	return 0;
}