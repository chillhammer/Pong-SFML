
#pragma once
#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics\Rect.hpp>
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
	sf::Vector2f GetPosition();
	void SetPosition(float, float);
	void SetPosition(sf::Vector2f);

	virtual void Update(float) = 0;
	virtual void Draw(sf::RenderWindow*);
	virtual sf::Vector2f GetHalfExtents();
	virtual sf::FloatRect GetBoundingBox();

protected:
	sf::Shape* shape;
};

