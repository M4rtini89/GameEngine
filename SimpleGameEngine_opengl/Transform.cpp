#include "Transform.h"
#include "Matrix4f.h"
#include "SFML\System\Vector3.hpp"


Transform::Transform() : m_translation(0, 0, 0), m_rotation(0, 0, 0), m_scale(1,1,1)
{
}


Transform::~Transform()
{
}

Matrix4f Transform::getTransform() const
{
	Matrix4f transformMatrix;
	Matrix4f rotationMatrix;
	Matrix4f scaleMatrix;
	transformMatrix.initTranslate(m_translation.x, m_translation.y, m_translation.z);
	rotationMatrix.initRotate(m_rotation.x, m_rotation.y, m_rotation.z);
	scaleMatrix.initScale(m_scale.x, m_scale.y, m_scale.z);
	return transformMatrix * rotationMatrix * scaleMatrix;
}

void Transform::setTranslate(sf::Vector3f vec)
{
	setTranslate(vec.x, vec.y, vec.z);
}

void Transform::setTranslate(float x, float y, float z)
{
	m_translation.x = x;
	m_translation.y = y;
	m_translation.z = z;
}

void Transform::setRotate(const sf::Vector3f vec)
{
	setRotate(vec.x, vec.y, vec.z);
}

void Transform::setRotate(const float x, const float y, const float z)
{
	m_rotation.x = x;
	m_rotation.y = y;
	m_rotation.z = z;
}

void Transform::setScale(const sf::Vector3f vec)
{
	setScale(vec.x, vec.y, vec.z);
}

void Transform::setScale(const float x, const float y, const float z)
{
	m_scale.x = x;
	m_scale.y = y;
	m_scale.z = z;
}

void Transform::setProjection(float fov, float width, float height, float zNear, float zFar)
{
	Transform::fov = fov;
	Transform::width = width;
	Transform::height = height;
	Transform::zNear = zNear;
	Transform::zFar = zFar;
}

Matrix4f Transform::getProjectedTransform()
{
	Matrix4f transformationMatrix = getTransform();
	Matrix4f projectionMatrix = Matrix4f().initProjection(fov, width, height, zNear, zFar);
	Matrix4f cameraRotation = Matrix4f().initCamera(m_camera->Forward(), m_camera->Up());
	Matrix4f cameraTranslation = Matrix4f().initTranslate(-m_camera->Pos().x, -m_camera->Pos().y, -m_camera->Pos().z);


	return projectionMatrix * cameraRotation * cameraTranslation *transformationMatrix;

}

float Transform::zNear;
float Transform::zFar;
float Transform::width;
float Transform::height;
float Transform::fov;