
#pragma once
#include <SFML\System\Vector2.hpp>
namespace sf {
	class Shape;
	class RenderWindow;
}
class Entity
{
public:
	Entity();
	Entity(sf::Shape* s) : shape(s) {};
	virtual ~Entity();
	void setPosition(float, float);
	void setPosition(sf::Vector2f);

	virtual void Update(float) = 0;
	virtual void Draw(sf::RenderWindow*);

protected:
	sf::Shape* shape;
};

