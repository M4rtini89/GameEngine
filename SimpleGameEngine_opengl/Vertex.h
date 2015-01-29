#pragma once
#include "SFML\System\Vector3.hpp"
#include "SFML\System\Vector2.hpp"

struct Vertex
{
	sf::Vector3f pos;
	sf::Vector2f texCord;
	sf::Vector3f normal;

	Vertex(sf::Vector3f pos, sf::Vector2f texCord = sf::Vector2f(0,0), sf::Vector3f normal = sf::Vector3f(0, 0, 0)) 
		: pos(pos), 
		texCord(texCord), 
		normal(normal) {}
};

