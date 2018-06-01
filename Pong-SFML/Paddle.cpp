#include "Paddle.h"
#include "SFML\Graphics.hpp"



Paddle::Paddle() : accSpeed(0.01f), MovingEntity()
{
	sf::Vector2f size(15.0f, 60.0f);
	shape = new sf::RectangleShape(size);
	shape->setFillColor(sf::Color::White);
	shape->setPosition(10.f, 10.f);
	maxSpeed = 0.5f;
	friction = 0.2f;
}


Paddle::~Paddle()
{
	delete shape;
}

void Paddle::Update() {

	//Input
	int up = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || 
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) ? 1 : 0;
	int down = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || 
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) ? 1 : 0;
	int moveVer = down - up;

	acceleration = sf::Vector2f(0, moveVer * accSpeed);

	//Move
	MoveBasedOnVelocity();
}