#include "Game.h"
#include <SFML\Graphics.hpp>

sf::RenderWindow Game::window(sf::VideoMode(640, 480), "SFML works!", sf::Style::Close);

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
