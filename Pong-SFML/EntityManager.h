#include <vector>
#include "Entity.h"
#pragma once
#define EntMgr EntityManager::instance()
class EntityManager
{
public:
	static EntityManager& instance() {

		static EntityManager e;
		return e;
	}
	void Add(Entity*);
	void UpdateAll(float);
	void DrawAll();
	~EntityManager();
private:
	EntityManager();
	std::vector<Entity*> entities;
};

