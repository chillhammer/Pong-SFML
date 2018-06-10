#include <SFML\Graphics.hpp>
#include "EntityManager.h"
#pragma once
class Game
{
public:
	Game();
	~Game();
	static const int HEIGHT;
	static const int WIDTH;
	static sf::RenderWindow* GetWindow();
	static void HandleEvents();
	static void PutOnWindow(Entity*);
	static void Draw();

	template <class instance>
	static instance* Spawn(float x, float y);
	static void Destroy(Entity* entity);
	
private:
	static sf::RenderWindow window;
};

//Template methods
template <class instance>
instance* Game::Spawn(float x, float y)
{
	instance* inst = new instance();
	inst->SetPosition(x, y);
	EntMgr.Add(inst);
	return inst;
}
