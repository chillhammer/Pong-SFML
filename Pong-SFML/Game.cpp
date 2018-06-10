#include "Game.h"
#include "EntityManager.h"
#include <SFML\Graphics.hpp>

const int Game::HEIGHT = 480;
const int Game::WIDTH  = 640;

sf::RenderWindow Game::window(sf::VideoMode(Game::WIDTH, Game::HEIGHT), "Pong!", sf::Style::Close);

Game::Game()
{
	
}


Game::~Game()
{
}

sf::RenderWindow* Game::GetWindow()
{
	return &window;
}

void Game::HandleEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Game::PutOnWindow(Entity* entity)
{
	entity->Draw(&window);
}

void Game::Draw()
{
	//sf::RenderWindow& window = *Game::GetWindow();
	window.clear();

	EntMgr.DrawAll();

	window.display();
}

void Game::Destroy(Entity * entity)
{
	EntMgr.Remove(entity);
	delete entity;
}


