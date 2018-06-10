#include "Entity.h"
#include "Game.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

sf::Vector2f Entity::GetPosition()
{
	return shape->getPosition();
}

void Entity::SetPosition(float x, float y)
{
	shape->setPosition(x, y);
}

void Entity::SetPosition(sf::Vector2f newPos)
{
	shape->setPosition(newPos);
}

void Entity::Draw(sf::RenderWindow* window)
{
	//TODO: Put onto window;
	window->draw(*shape);
}

sf::Vector2f Entity::GetHalfExtents()
{
	return sf::Vector2f();
}

sf::FloatRect Entity::GetBoundingBox()
{
	return shape->getGlobalBounds();
}