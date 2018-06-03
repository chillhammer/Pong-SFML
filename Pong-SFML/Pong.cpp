#include <SFML\Graphics.hpp>

#include "Game.h"
#include "Paddle.h"
static void loadRoom();

int main()
{
	sf::Clock clock;
	
	loadRoom();
	while (Game::GetWindow()->isOpen())
	{
		float deltaTime = clock.restart().asSeconds();
		Game::HandleEvents();

		EntMgr.UpdateAll(deltaTime);

		Game::Draw();
	}

	return 0;
}

void loadRoom() 
{
	Paddle* player = new Paddle();
	EntMgr.Add(player);
}