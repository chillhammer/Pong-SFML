#include "MovingEntity.h"
#include "Util.h"

MovingEntity::MovingEntity()
{
}

MovingEntity::~MovingEntity()
{
}

void MovingEntity::MoveBasedOnVelocity()
{
	sf::Vector2f nextVelocity = velocity + acceleration;
	if (Util::Vector2fLength(nextVelocity) < maxSpeed) {
		velocity = nextVelocity;
	}
	else {
		velocity = Util::Vector2fNormalize(nextVelocity) * maxSpeed;
	}
	
	shape->move(velocity);
}
