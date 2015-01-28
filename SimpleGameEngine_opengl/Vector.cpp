#include "Vector.h"
#include <cmath>
#include <algorithm>
#include <SFML\System\Vector2.hpp>
#include "Quaternion.h"

const double PI = std::acos(-1);

double toRad(double deg)
{
	return deg * PI / 180.0;
}


namespace Vector
{
	float length(const sf::Vector2f v)
	{
		return std::sqrt(v.x*v.x + v.y*v.y);
	}

	float length(const sf::Vector3f v)
	{
		return std::sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
	}

	//float max(const sf::Vector2f v)
	//{
	//	return std::max(v.x, v.y);
	//}

	sf::Vector2f normalized(const sf::Vector2f v)
	{
		return v / length(v);
	}

	sf::Vector3f normalized(const sf::Vector3f v)
	{
		return v / length(v);
	}

	sf::Vector2f abs(const sf::Vector2f v)
	{
		return sf::Vector2f(std::abs(v.x), std::abs(v.y));
	}

	sf::Vector3f abs(const sf::Vector3f v)
	{
		return sf::Vector3f(std::abs(v.x), std::abs(v.y), std::abs(v.z));
	}

	sf::Vector2f rotate(const sf::Vector2f v, const float angle)
	{
		double rad = toRad(angle);
		double cos = std::cos(rad);
		double sin = std::sin(rad);

		return sf::Vector2f(v.x * cos - v.y * sin, 
							v.x * sin + v.y * cos);
	}

	sf::Vector3f rotate(sf::Vector3f v, float angle, sf::Vector3f axis)
	{
		float sinHalfAngle = sin(toRad(angle / 2));
		float cosHalfAngle = cos(toRad(angle / 2));

		float rX = axis.x * sinHalfAngle;
		float rY = axis.y * sinHalfAngle;
		float rZ = axis.z * sinHalfAngle;
		float rW = cosHalfAngle;

		Quaternion rotation = Quaternion(rX, rY, rZ, rW);

		Quaternion w = rotation * v * rotation.conjugate();

		return sf::Vector3f(w.x, w.y, w.z);

	}

	//float cross(sf::Vector2f lhs, sf::Vector2f rhs)
	//{
	//	return lhs.x * rhs.y - lhs.y * rhs.x;
	//}

	sf::Vector3f cross(const sf::Vector3f lhs, const sf::Vector3f rhs)
	{
		float x_ = lhs.y * rhs.z - lhs.z * rhs.y;
		float y_ = lhs.z * rhs.x - lhs.x * rhs.z;
		float z_ = lhs.x * rhs.y - lhs.y * rhs.x;
		return sf::Vector3f(x_, y_, z_);
	}


	float dot(const sf::Vector2f lhs, const sf::Vector2f rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	float dot(const sf::Vector3f lhs, const sf::Vector3f rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}


}