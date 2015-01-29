#pragma once
#include "SFML\Window\Event.hpp"
#include "SFML\System\Time.hpp"
#include "Mesh.h"
#include "Transform.h"
#include "BasicShader.h"
#include "Material.h"
#include "PhongShader.h"

class Game
{
private:
	Mesh m_mesh;
	PhongShader m_shader;
	Transform m_transform;
	Camera m_camera;
	Material m_material;
public:

	void input();
	void update(const float dt);
	void render();

	Game();
	~Game();
};

