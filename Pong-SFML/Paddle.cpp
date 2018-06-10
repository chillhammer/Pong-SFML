#include <algorithm>
#include "Ball.h"
#include "EntityManager.h"
#include "Game.h"
#include "Paddle.h"
#include "SFML\Graphics.hpp"
#include <functional>
#include <iostream>



Paddle::Paddle() : accSpeed(2.f), MovingEntity()
{
	//Setting Sprite
	sf::Vector2f size(15.0f, 60.0f);
	shape = new sf::RectangleShape(size);
	shape->setFillColor(sf::Color::White);
	shape->setPosition(20.f, 10.f);
	shape->setOrigin(7.5f, 30.f);
	//Setting Physics Variables
	maxSpeed = 275.f;
	friction = 2.f;

	SetPaddleType(Player);
}


Paddle::~Paddle()
{
	delete shape;
}

void Paddle::Update(float deltaTime) {

	//Calls Appropriate Input Function
	int moveVer = std::invoke(Input, this);

	acceleration = sf::Vector2f(0, moveVer * accSpeed);

	//Reset Velocity
	if (acceleration.y > 0 && velocity.y < 0 ||
		acceleration.y < 0 && velocity.y > 0) {
		velocity = sf::Vector2f(0.f, 0.f);
	}

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

sf::Vector2f Paddle::GetHalfExtents()
{
	return sf::Vector2f(shape->getGlobalBounds().width, shape->getGlobalBounds().height);
}

void Paddle::SetPaddleType(Control type)
{
	paddleType = type;
	switch (type) {
		case Player:
			Input = &Paddle::PlayerInput;
			break;
		case Enemy:
			Input = &Paddle::EnemyInput;
			break;
	}
}

int Paddle::PlayerInput()
{
	//Input
	int up = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) ? 1 : 0;
	int down = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) ? 1 : 0;
	return down - up;
}

int Paddle::EnemyInput()
{
	//Find Ball
	Entity* ball = EntMgr.FindFirstOfType<Ball*>();

	if (ball != nullptr) {
		float ballY = ball->GetPosition().y;
		float y = GetPosition().y;
		if (y > ballY) return -1;
		if (y < ballY) return 1;
	}
	return 0;
}
