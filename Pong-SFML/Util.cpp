#include "SFML\System\Vector2.hpp"
#include "Util.h"
#include <cmath>

float Util::Vector2fLength(sf::Vector2f vector)
{
	return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

sf::Vector2f Util::Vector2fNormalize(sf::Vector2f vector)
{
	float length = Util::Vector2fLength(vector);
	if (length == 0.f) return vector;
	return vector / length;
}

bool Util::Vector2fIsZero(const sf::Vector2f& vector)
{
	return vector.x == 0 && vector.y == 0;
}
