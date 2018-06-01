#pragma once

#include <SFML\Graphics.hpp>
#include "Entity.h"
class MovingEntity :
	public Entity
{
public:
	MovingEntity();
	MovingEntity(sf::Shape* s) : Entity(s) {};
	virtual ~MovingEntity();
	virtual void Update() = 0;
protected:
	sf::Vector2f acceleration;
	sf::Vector2f velocity;
	float maxSpeed; //must set to move
	float friction;
	
	void MoveBasedOnVelocity();
};

