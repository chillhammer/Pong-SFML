#pragma once
#include "Entity.h"
class StaticEntity :
	public Entity
{
public:
	StaticEntity();
	virtual ~StaticEntity();
	virtual void Update(float);
};

