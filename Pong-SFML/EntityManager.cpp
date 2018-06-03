#include "EntityManager.h"
#include "Game.h"


EntityManager::EntityManager() : entities()
{
}


void EntityManager::Add(Entity * entity)
{
	entities.push_back(entity);
}

void EntityManager::UpdateAll(float deltaTime)
{
	for (Entity* entity : entities) {
		entity->Update(deltaTime);
	}
}

void EntityManager::DrawAll()
{
	for (Entity* entity : entities) {
		Game::PutOnWindow(entity);
	}
}

EntityManager::~EntityManager()
{
}
