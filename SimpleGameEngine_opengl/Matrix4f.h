#pragma once

#include <vector>
#include "SFML\System\Vector3.hpp"


class Matrix4f
{
private:
	std::vector<float> m_data;
	const int m_rows = 4;
	const int m_cols = 4;
public:

	const float* raw_pointer(){ return m_data.data(); }
	float& operator()(size_t i, size_t j);
	float operator()(size_t i, size_t j) const;

	Matrix4f& initIdentity();
	Matrix4f& initTranslate(const float x, const float y, const float z);
	Matrix4f& initTranslate(const sf::Vector3f &translate );
	Matrix4f& initRotate(const float x, const float y, const float z);
	Matrix4f& initRotate(const sf::Vector3f &rotation);
	Matrix4f& initScale(const float x, const float y, const float z);
	Matrix4f& initScale(const sf::Vector3f &scale);
	Matrix4f& initProjection(float fov, float width, float height, float zNear, float zFar);
	Matrix4f& initCamera(const sf::Vector3f forward, const sf::Vector3f up);


	Matrix4f operator*(const Matrix4f&);
	Matrix4f();
	~Matrix4f();
};

