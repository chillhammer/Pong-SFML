#include <SFML\Graphics.hpp>

#include "Game.h"
#include "Paddle.h"
#include "Ball.h"
#include "Wall.h"
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
	Paddle* player = Game::Spawn<Paddle>(20.f, Game::HEIGHT * 0.5f);
	Paddle* enemy = Game::Spawn<Paddle>(Game::WIDTH - 35.f, Game::HEIGHT * 0.5f);
	enemy->SetPaddleType(Enemy);
	Wall* topWall = Game::Spawn<Wall>(35.f, 10.f);
	Wall* bottomWall = Game::Spawn<Wall>(35.f, Game::HEIGHT - 25.f);
	Ball* ball = Game::Spawn<Ball>(Game::WIDTH * 0.5f, Game::HEIGHT * 0.5f);
	ball->SetCollidingReferences(topWall, bottomWall, player, enemy);
}