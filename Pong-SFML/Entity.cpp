#include "Entity.h"
#include "Game.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::Draw(sf::RenderWindow* window)
{
	//TODO: Put onto window;
	window->draw(*shape);
}
