#pragma once
#include "SFML\System\Vector3.hpp"
#include "Matrix4f.h"
#include "Camera.h"
class Transform
{
private:

	static float zNear;
	static float zFar;
	static float width;
	static float height;
	static float fov;

	sf::Vector3f m_translation;
	sf::Vector3f m_rotation;
	sf::Vector3f m_scale;

	static Camera* m_camera;

public:

	void setTranslate(const sf::Vector3f vec);
	void setTranslate(const float x, const float y, const float z);
	void setRotate(const sf::Vector3f vec);
	void setRotate(const float x, const float y, const float z);
	void setScale(const sf::Vector3f vec);
	void setScale(const float x, const float y, const float z);
	static Camera* getCamera() { return m_camera; };
	void setCamera(Camera* val) { m_camera = val; };


	sf::Vector3f getTranslation() const;
	Matrix4f getTransform() const;
	Matrix4f getProjectedTransform();
	static void setProjection(float fov, float width, float height, float zNear, float zFar);
	Transform();
	~Transform();
};

