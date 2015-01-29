#pragma once
#include "SFML\System\Vector3.hpp"

struct BaseLight
{
	sf::Vector3f color;
	float intensity;

	BaseLight(const sf::Vector3f& color = sf::Vector3f(0, 0, 0), float intensity = 0) :
		color(color),
		intensity(intensity) {}
};

