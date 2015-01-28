#include "Camera.h"
#include "Vector.h"
#include "SFML\System\Vector3.hpp"
#include "Input.h"
#include "SFML\Window\Keyboard.hpp"
#include <iostream>

using Vector::normalized; 
using Vector::cross;
using Vector::dot;
using Vector::rotate;

Camera::Camera(sf::Vector3f pos, sf::Vector3f forward, sf::Vector3f up) :m_pos(pos), m_forward(forward), m_up(up)
{
	m_up = normalized(up);
	m_forward = normalized(forward);
}

Camera::Camera() : m_pos(0, 0, 0), m_forward(0, 0, 1), m_up(0, 1, 0)
{

}


Camera::~Camera()
{
}

void Camera::move(sf::Vector3f dir, float amt)
{
	m_pos += dir*amt;
}

sf::Vector3f Camera::getLeft() const
{
	
	return normalized(cross(m_forward, m_up));
}

sf::Vector3f Camera::getRight() const
{
	return normalized(cross(m_up, m_forward));
}

void Camera::rotateX(float angle)
{
	sf::Vector3f Haxis = normalized(cross(yAxis, m_forward));

	m_forward = normalized(rotate(m_forward, angle, Haxis));

	m_up = normalized(cross(m_forward, Haxis));

}

void Camera::rotateY(float angle)
{
	sf::Vector3f Haxis = normalized(cross(yAxis, m_forward));

	m_forward = normalized(rotate(m_forward, angle, yAxis));

	m_up = normalized(cross(m_forward, Haxis));

}

void Camera::input(float dt)
{
	float moveAmt = 10 * dt;
	float rotAmt = 100 * dt;

	

	if (Input::getKey(sf::Keyboard::W))
		move(Forward(), moveAmt);
	if (Input::getKey(sf::Keyboard::S))
		move(Forward(), -moveAmt);
	if (Input::getKey(sf::Keyboard::A))
		move(getLeft(), moveAmt);
	if (Input::getKey(sf::Keyboard::D))
		move(getRight(), moveAmt);
	if (Input::getKey(sf::Keyboard::Up))
		rotateX(-rotAmt);
	if (Input::getKey(sf::Keyboard::Down))
		rotateX(rotAmt);
	if (Input::getKey(sf::Keyboard::Left))
		rotateY(-rotAmt);
	if (Input::getKey(sf::Keyboard::Right))
		rotateY(rotAmt);
}

const sf::Vector3f Camera::yAxis = sf::Vector3f(0, 1, 0);
