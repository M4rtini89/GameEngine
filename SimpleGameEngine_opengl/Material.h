#pragma once
#include "Texture.h"
#include "SFML\System\Vector3.hpp"
class Material
{
private: 
	Texture texture;
	sf::Vector3f color;
	float m_specularIntensity;
	float m_specularPower;

public:

	Texture getTexture() const { return texture; }
	void setTexture(Texture val) { texture = val; }
	sf::Vector3f getColor() const { return color; }
	void setColor(sf::Vector3f val) { color = val; }

	Material(Texture texture, sf::Vector3f color, 
		float specularIntensity=2, float specularPower=32)
		: texture(texture), color(color),
		m_specularIntensity(specularIntensity), m_specularPower(specularPower){};

	float getSpecularIntensity() const { return m_specularIntensity; }
	void setSpecularIntensity(float val) { m_specularIntensity = val; }
	float getSpecularPower() const { return m_specularPower; }
	void setSpecularPower(float val) { m_specularPower = val; }

};

