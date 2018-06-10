#pragma once
#include "MovingEntity.h"
enum Control {
	Player, Enemy
};


class Paddle :
	public MovingEntity
{
public:
	Paddle();
	virtual ~Paddle();
	virtual void Update(float);
	sf::Vector2f GetHalfExtents();
	void SetPaddleType(Control);
private:
	int PlayerInput();
	int EnemyInput();
	int (Paddle::*Input)();
	float accSpeed;
	Control paddleType;
};

