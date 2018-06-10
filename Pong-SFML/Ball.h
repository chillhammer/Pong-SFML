#pragma once
#include "MovingEntity.h"
#include "Paddle.h"
#include "Wall.h"
class Ball :
	public MovingEntity
{
public:
	Ball();
	virtual ~Ball();
	virtual void Update(float);
	void SetCollidingReferences(Wall* top, Wall* bottom, Paddle*, Paddle*);
	bool IsColliding(Entity*);
private:
	Wall * topWall;
	Wall * bottomWall;
	Paddle* player;
	Paddle* enemy;
};

