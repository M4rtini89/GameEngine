#include "Matrix4f.h"
#include <cmath>
#include "Vector.h"

const float PI = (float)std::acos(-1);

float toRad(float deg)
{
	return deg * PI / 180.0f;
}


Matrix4f& Matrix4f::initIdentity()
{
	for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				(*this)(i, j) = (j == i);
			}
		}
	return *this;
}

Matrix4f Matrix4f::operator*(const Matrix4f& rhs)
{
	Matrix4f result;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result(i, j) =  (*this)(i, 0) * rhs(0, j) +
							(*this)(i, 1) * rhs(1, j) +
							(*this)(i, 2) * rhs(2, j) +
							(*this)(i, 3) * rhs(3, j);
		}
	}
	return result;
}

float& Matrix4f::operator()(size_t i, size_t j)
{
	return m_data[i * m_cols + j];
}

float Matrix4f::operator()(size_t i, size_t j) const
{
	return m_data[i * m_cols + j];
}

Matrix4f::Matrix4f() : m_data(4*4, 0) //default init with 4x4 filled with 0
{
}


Matrix4f::~Matrix4f()
{
}

Matrix4f& Matrix4f::initTranslate(const sf::Vector3f &translate)
{
	return initTranslate(translate.x, translate.y, translate.z);
}

Matrix4f& Matrix4f::initTranslate(const float x, const float y, const float z)
{
	initIdentity();
	(*this)(0, 3) = x;
	(*this)(1, 3) = y;
	(*this)(2, 3) = z;

	return *this;
}

Matrix4f& Matrix4f::initRotate(const sf::Vector3f & rotation)
{
	return initRotate(rotation.x, rotation.y, rotation.z);
}

Matrix4f& Matrix4f::initRotate(const float x_, const float y_, const float z_)
{
/*
Full form rotation matrix along 3 axes derived from:
http://www.wolframalpha.com/input/?i=%7B%7Bcos%28z%29%2C-sin%28z%29%2C0%2C0%7D%2C%7Bsin%28z%29%2Ccos%28z%29%2C0%2C0%7D%2C%7B0%2C0%2C1%2C0%7D%2C%7B0%2C0%2C0%2C1%7D%7D*%7B%7Bcos%28y%29%2C0%2Csin%28y%29%2C0%7D%2C%7B0%2C1%2C0%2C0%7D%2C%7B-sin%28y%29%2C0%2Ccos%28y%29%2C0%7D%2C%7B0%2C0%2C0%2C1%7D%7D*%7B%7B1%2C0%2C0%2C0%7D%2C%7B0%2Ccos%28x%29%2C-sin%28x%29%2C0%7D%2C%7B0%2Csin%28x%29%2Ccos%28x%29%2C0%7D%2C%7B0%2C0%2C0%2C1%7D%7D
*/
	using std::cos; using std::sin;
	float x = toRad(x_);
	float y = toRad(y_);
	float z = toRad(z_);

	(*this)(0, 0) = cos(y)*cos(z); 
	(*this)(1, 0) = cos(y)*sin(z);
	(*this)(2, 0) = -sin(y);
	(*this)(3, 0) = 0;

	(*this)(0, 1) = cos(z)*sin(x)*sin(y) - cos(x)*sin(z);
	(*this)(1, 1) = cos(x)*cos(z) + sin(x)*sin(y)*sin(z);
	(*this)(2, 1) = cos(y)*sin(x);
	(*this)(3, 1) = 0;
	
	(*this)(0, 2) = cos(x)*cos(z)*sin(y) + sin(x)*sin(z);
	(*this)(1, 2) = cos(x)*sin(y)*sin(z) - cos(z)*sin(x);
	(*this)(2, 2) = cos(x)*cos(y);
	(*this)(3, 2) = 0;

	(*this)(0, 3) = 0;
	(*this)(1, 3) = 0;
	(*this)(2, 3) = 0;
	(*this)(3, 3) = 1;

	return *this;
}

Matrix4f& Matrix4f::initScale(const sf::Vector3f &scale)
{
	return initScale(scale.x, scale.y, scale.z);
}

Matrix4f& Matrix4f::initScale(const float x, const float y, const float z)
{
	
	initIdentity();
	(*this)(0, 0) = x;
	(*this)(1, 1) = y;
	(*this)(2, 2) = z;

	return *this;
}

Matrix4f& Matrix4f::initProjection(float fov, float width, float height, float zNear, float zFar)
{
	float tanHalfFOV = std::tan(toRad(fov / 2));
	float ar = width / height;
	float zRange = zNear - zFar;

	initIdentity();
	(*this)(0, 0) = 1.f / (ar * tanHalfFOV);
	(*this)(1, 1) = 1.f / tanHalfFOV;
	(*this)(2, 2) = (-zNear - zFar) / zRange;
	(*this)(2, 3) = 2 * zFar * zNear / zRange;
	(*this)(3, 2) = 1;
	(*this)(3, 3) = 0;


	return *this;
}

Matrix4f& Matrix4f::initCamera(const sf::Vector3f forward, const sf::Vector3f up)
{
	initIdentity();
	sf::Vector3f f = Vector::normalized(forward);

	sf::Vector3f r = Vector::normalized(Vector::cross(up, f));

	sf::Vector3f u = Vector::cross(f, r);

	(*this)(0, 0) = r.x;
	(*this)(0, 1) = r.y;
	(*this)(0, 2) = r.z;

	(*this)(1, 0) = u.x;
	(*this)(1, 1) = u.y;
	(*this)(1, 2) = u.z;

	(*this)(2, 0) = f.x;
	(*this)(2, 1) = f.y;
	(*this)(2, 2) = f.z;

	return *this;
	
}
