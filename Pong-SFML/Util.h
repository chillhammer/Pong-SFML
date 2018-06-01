#include <SFML\System\Vector2.hpp>
#pragma once
namespace Util
{
	float Vector2fLength(sf::Vector2f);
	sf::Vector2f Vector2fNormalize(sf::Vector2f);
	bool Vector2fIsZero(const sf::Vector2f&);
}