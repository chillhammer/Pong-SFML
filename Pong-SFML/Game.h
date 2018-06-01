#include <SFML\Graphics.hpp>
#include "EntityManager.h"
#pragma once
class Game
{
public:
	Game();
	~Game();
	static sf::RenderWindow* GetWindow();
	static void HandleEvents();
	static void Draw();
private:
	static sf::RenderWindow window;
};

