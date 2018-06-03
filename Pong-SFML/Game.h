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
private:
	static sf::RenderWindow window;
};

