#pragma once
#include "BaseLight.h"
#include "SFML\System\Vector3.hpp"
#include "Vector.h"

struct DirectionalLight
{
	BaseLight base;
	sf::Vector3f direction;

	DirectionalLight(const BaseLight& base = BaseLight(), sf::Vector3f direction = sf::Vector3f(0, 0, 0)) :
		base(base),
		direction(Vector::normalized(direction)) {}
};
