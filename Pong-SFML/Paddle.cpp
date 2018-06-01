#include "Paddle.h"
#include "SFML\Graphics.hpp"



Paddle::Paddle()
{
	sf::Vector2f size(10.0f, 20.0f);
	shape = new sf::RectangleShape(size);
	shape->setFillColor(sf::Color::White);
	shape->setPosition(10.f, 10.f);
}


Paddle::~Paddle()
{
	delete shape;
}

void Paddle::Update() {
	//Move
}