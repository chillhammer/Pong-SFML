#include "Wall.h"
#include "Game.h"


Wall::Wall()
{
	//Setting Sprite
	shape = new sf::RectangleShape(sf::Vector2f(Game::WIDTH - 85, 15.f));
	shape->setFillColor(sf::Color::White);
}


Wall::~Wall()
{
}

sf::Vector2f Wall::GetHalfExtents()
{
	return sf::Vector2f(shape->getGlobalBounds().width, shape->getGlobalBounds().height);
}
