#include "EntityManager.h"


EntityManager::EntityManager() : entities()
{
}


void EntityManager::Add(Entity * entity)
{
	entities.push_back(entity);
}

void EntityManager::UpdateAll()
{
	for (Entity* entity : entities) {
		entity->Update();
	}
}

void EntityManager::DrawAll()
{
	for (Entity* entity : entities) {
		entity->Draw();
	}
}

EntityManager::~EntityManager()
{
}
