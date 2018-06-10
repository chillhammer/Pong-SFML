#pragma once
#include "StaticEntity.h"
class Wall :
	public StaticEntity
{
public:
	Wall();
	virtual ~Wall();
	sf::Vector2f GetHalfExtents();
};

