
#pragma once

namespace sf {
	class Shape;
}
class Entity
{
public:
	Entity();
	Entity(sf::Shape* s) : shape(s) {};
	virtual ~Entity();

	virtual void Update() = 0;
	virtual void Draw();

protected:
	sf::Shape* shape;
};

