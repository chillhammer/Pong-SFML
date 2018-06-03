#include "Entity.h"
#include "Game.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::setPosition(float x, float y)
{
	shape->setPosition(x, y);
}

void Entity::setPosition(sf::Vector2f newPos)
{
	shape->setPosition(newPos);
}

void Entity::Draw(sf::RenderWindow* window)
{
	//TODO: Put onto window;
	window->draw(*shape);
}
