#pragma once
#include "MovingEntity.h"
class Paddle :
	public MovingEntity
{
public:
	Paddle();
	virtual ~Paddle();
	virtual void Update();
};

