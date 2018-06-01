#include "MovingEntity.h"
#include "Util.h"
#include <iostream>

MovingEntity::MovingEntity() : velocity(0.f, 0.f), acceleration(0.f, 0.f)
{
}

MovingEntity::~MovingEntity()
{
}

void MovingEntity::MoveBasedOnVelocity()
{
	//Acceleration
	sf::Vector2f nextVelocity = velocity + acceleration;
	if (Util::Vector2fIsZero(nextVelocity)) return;

	//Max Speed
	if (Util::Vector2fLength(nextVelocity) < maxSpeed) {
		velocity = nextVelocity;
	}
	else {
		velocity = Util::Vector2fNormalize(nextVelocity) * maxSpeed;
	}

	shape->move(velocity);

	//Friction
	if (Util::Vector2fIsZero(acceleration)) { 
		velocity -= Util::Vector2fNormalize(velocity) * friction;
		if (Util::Vector2fIsZero(velocity) <= friction)
			velocity = sf::Vector2f(0, 0);;
	}
	else {
		//Reset Acceleration
		acceleration = sf::Vector2f(0, 0);
	}
	
}
