#include <algorithm>
#include "Game.h"
#include "Paddle.h"
#include "SFML\Graphics.hpp"



Paddle::Paddle() : accSpeed(2.f), MovingEntity()
{
	//Setting Sprite
	sf::Vector2f size(15.0f, 60.0f);
	shape = new sf::RectangleShape(size);
	shape->setFillColor(sf::Color::White);
	shape->setPosition(20.f, 10.f);
	shape->setOrigin(7.5f, 30.f);
	//Setting Physics Variables
	maxSpeed = 250.f;
	friction = 0.1f;
}


Paddle::~Paddle()
{
	delete shape;
}

void Paddle::Update(float deltaTime) {

	//Input
	int up = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || 
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) ? 1 : 0;
	int down = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || 
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) ? 1 : 0;
	int moveVer = down - up;

	acceleration = sf::Vector2f(0, moveVer * accSpeed);

	//Move
	MoveBasedOnVelocity(deltaTime);

	//Clamp Y
	float pad = 10.f;
	float halfHeight = ((sf::RectangleShape*)shape)->getSize().y * 0.5f;
	float currentY = shape->getPosition().y;
	float topY = pad + halfHeight; //because origin is in center
	float bottomY = Game::HEIGHT - pad - halfHeight;
	float newY = std::max(topY, std::min(bottomY, currentY));
	shape->setPosition(shape->getPosition().x, newY);
}