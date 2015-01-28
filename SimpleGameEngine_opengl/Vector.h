#pragma once
#include "SFML\System\Vector2.hpp"
#include "SFML\System\Vector3.hpp"



namespace Vector
{

	float length(const sf::Vector2f v);
	float length(const sf::Vector3f v);
	//float max(const sf::Vector2f v);
	sf::Vector2f normalized(const sf::Vector2f v);
	sf::Vector3f normalized(const sf::Vector3f v);
	sf::Vector2f abs(const sf::Vector2f v);
	sf::Vector3f abs(const sf::Vector3f v);
	sf::Vector2f rotate(const sf::Vector2f v, float angle);
	sf::Vector3f rotate(sf::Vector3f v, float angle, sf::Vector3f axis);
	//float cross(sf::Vector2f lhs, sf::Vector2f rhs);
	sf::Vector3f cross(const sf::Vector3f lhs, const sf::Vector3f rhs);
	float dot(const sf::Vector2f lhs, const sf::Vector2f rhs);
	float dot(const sf::Vector3f lhs, const sf::Vector3f rhs);

};
