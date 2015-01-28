#pragma once
#include "Texture.h"
#include "SFML\System\Vector3.hpp"
class Material
{
private: 
	Texture texture;
	sf::Vector3f color;
public:

	Texture getTexture() const { return texture; }
	void setTexture(Texture val) { texture = val; }
	sf::Vector3f getColor() const { return color; }
	void setColor(sf::Vector3f val) { color = val; }

	Material(Texture texture, sf::Vector3f color) : texture(texture), color(color) {};
};

