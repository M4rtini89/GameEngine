#pragma once
#include "SFML\System\Vector3.hpp"
class Camera
{
private:
	static const sf::Vector3f yAxis;
	sf::Vector3f m_pos;

	sf::Vector3f m_up;

	sf::Vector3f m_forward;
public:
	//Getter and setters
	sf::Vector3f Forward() const { return m_forward; }
	void Forward(sf::Vector3f val) { m_forward = val; }
	sf::Vector3f Up() const { return m_up; }
	void Up(sf::Vector3f val) { m_up = val; }
	sf::Vector3f Pos() const { return m_pos; }
	void Pos(sf::Vector3f val) { m_pos = val; }

	void move(sf::Vector3f dir, float amt);
	sf::Vector3f getLeft() const;
	sf::Vector3f getRight() const;
	void rotateX(float angle);
	void rotateY(float angle);

	void input(float dt);


	Camera();
	Camera(sf::Vector3f pos, sf::Vector3f forward, sf::Vector3f up);
	~Camera();
};

