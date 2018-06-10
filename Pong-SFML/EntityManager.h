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
	template <class type>
	Entity* FindFirstOfType();
	void Remove(Entity*);
	void UpdateAll(float);
	void DrawAll();
	~EntityManager();
private:
	EntityManager();
	std::vector<Entity*> entities;
};

template<class type>
inline Entity* EntityManager::FindFirstOfType()
{
	for (auto i = entities.begin(); i != entities.end(); ++i) {
		if (dynamic_cast<type>(*i)) {
			return *i;
		}
	}
	return nullptr;
}