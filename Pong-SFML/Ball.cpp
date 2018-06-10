#include "Ball.h"
#include "Game.h"
#include "Util.h"
#include <iostream>


Ball::Ball() 
{
	//srand(time(0));
	//Finding Walls


	//Setting Sprite
	shape = new sf::CircleShape(10.f);
	shape->setFillColor(sf::Color::White);
	shape->setOrigin(5.f, 5.f);

	//Find Random Direction
	float x1 = -0.7f;
	float y1 = 0.7f;

	float angle = (rand() % 184) / 100.f;
	float x2 = std::cos(angle) * x1 - std::sin(angle) * y1;
	float y2 = std::sin(angle) * x1 + std::cos(angle) * y1;
	sf::Vector2f direction = sf::Vector2f(x2, y2);

	//Setting Physics Variables
	maxSpeed = 275.f;
	friction = 0.f;

	velocity = direction * maxSpeed;
}


Ball::~Ball()
{
}

void Ball::Update(float deltaTime)
{
	sf::Vector2f oldPosition = GetPosition();
	MoveBasedOnVelocity(deltaTime);

	//Check if Outside
	float x = shape->getPosition().x;
	float radius = shape->getOrigin().x;
	if (x < -radius || x > Game::WIDTH + radius) {
		std::cout << "Ball is outside\n";

		Ball* ball = Game::Spawn<Ball>(Game::WIDTH * 0.5, Game::HEIGHT * 0.5);
		ball->SetCollidingReferences(topWall, bottomWall, player, enemy);
		Game::Destroy(this);
		return;
	}

	//Collision Checking

	//Walls
	if (IsColliding(topWall) || IsColliding(bottomWall)) {
		SetPosition(oldPosition);
		velocity = sf::Vector2f(velocity.x, velocity.y * -1.f);
	}

	//Paddles
	Paddle* collidingPaddle = nullptr;
	//Find Paddle
	if (IsColliding(player)) {
		collidingPaddle = player;
	}
	if (IsColliding(enemy)) {
		collidingPaddle = enemy;
	}
	//Bounce
	if (collidingPaddle != nullptr) {
		SetPosition(oldPosition);

		//Get Direction From Paddle Origin
		sf::Vector2f direction = Util::Vector2fNormalize(
			GetPosition() - collidingPaddle->GetPosition());

		velocity = direction *  Util::Vector2fLength(velocity);
	}
}

void Ball::SetCollidingReferences(Wall * top, Wall * bottom, Paddle * plyr, Paddle * enmy)
{
	topWall = top;
	bottomWall = bottom;
	player = plyr;
	enemy = enmy;
}

bool Ball::IsColliding(Entity* other)
{
	sf::FloatRect otherBounding = other->GetBoundingBox();
	sf::FloatRect bounding = shape->getGlobalBounds();

	return bounding.intersects(otherBounding);
}
