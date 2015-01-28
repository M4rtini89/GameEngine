#include "Quaternion.h"
#include <cmath>


float Quaternion::length() const
{
	return std::sqrt(x*x + y*y + z*z + w*w);
}

Quaternion Quaternion::normalize() const
{
	float _length = length();

	return Quaternion(x / _length, y / _length, z / _length, w / _length);
}

Quaternion Quaternion::operator*(const Quaternion rhs)
{
	float w_ = w * rhs.w - x * rhs.x - y * rhs.y - z * rhs.z;
	float x_ = x * rhs.w + w * rhs.x + y * rhs.z - z * rhs.y;
	float y_ = y * rhs.w + w * rhs.y + z * rhs.x - x * rhs.z;
	float z_ = z * rhs.w + w * rhs.z + x * rhs.y - y * rhs.x;

	return Quaternion(x_, y_, z_, w_);
}

Quaternion Quaternion::operator*(const sf::Vector3f rhs)
{
	float w_ = -x * rhs.x - y * rhs.y - z * rhs.z;
	float x_ = w * rhs.x + y * rhs.z - z * rhs.y;
	float y_ = w * rhs.y + z * rhs.x - x * rhs.z;
	float z_ = w * rhs.z + x * rhs.y - y * rhs.x;

	return Quaternion(x_, y_, z_, w_);
}



Quaternion::Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{
}

Quaternion::Quaternion() : x(0), y(0), z(0), w(0)
{
}


Quaternion::~Quaternion()
{
}

Quaternion Quaternion::conjugate() const
{
	return Quaternion(-x, -y, -z, w);
}
