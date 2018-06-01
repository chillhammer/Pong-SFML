#include "SFML\System\Vector2.hpp"
#include "Util.h"
#include <cmath>

float Util::Vector2fLength(sf::Vector2f vector)
{
	return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

sf::Vector2f Util::Vector2fNormalize(sf::Vector2f vector)
{

	return vector / Util::Vector2fLength(vector);
}
