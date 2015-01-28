#pragma once
#include "SFML\System\Vector3.hpp"

class Quaternion
{
public:
	float x;
	float y;
	float z;
	float w;

	float length() const;
	Quaternion normalize() const;
	Quaternion conjugate() const;

	Quaternion operator*(const Quaternion rhs);
	Quaternion operator*(const sf::Vector3f rhs);

	Quaternion();
	Quaternion(float x, float y, float z, float w);
	~Quaternion();
};

