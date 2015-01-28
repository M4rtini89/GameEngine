#pragma once
#include "SFML\Window\Event.hpp"
#include "SFML\System\Time.hpp"
#include "Mesh.h"
#include "Shader.h"
#include "Transform.h"
#include "Texture.h"

class Game
{
private:
	Mesh m_mesh;
	Shader m_shader;
	Transform m_transform;
	Camera m_camera;
	Texture m_texture;
public:

	void input();
	void update(const float dt);
	void render();

	Game();
	~Game();
};

