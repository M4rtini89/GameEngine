#include "Game.h"
#include <iostream>
#include "Input.h"
#include "MainComponent.h"
#include "Mesh.h"
#include "ResourceLoader.h"
#include "Shader.h"
#include "constants.h"
#include "Vector.h"
#include "RenderUtil.h"

void Game::input()
{
	if (Input::getMouseDown(sf::Mouse::Left))
		Input::setCursorLock(MainComponent::getWindow(), true);
	if (Input::getMouseUp(sf::Mouse::Left))
		Input::setCursorLock(MainComponent::getWindow(), false);
}

float temp_ = 0.0;
void Game::update(const float dt)
{
	//m_camera.input(dt);
	temp_ += dt;
	float sinTemp = std::sin(temp_);
	m_transform.setTranslate(0, 0, 5);
	m_transform.setRotate(0, sinTemp * 180, 0);
	//m_transform.setScale(0.5, 0.5, 0.5);
}

void Game::render()
{
	RenderUtil::setClearColor(Vector::abs(m_transform.getCamera()->Pos() / 2048.f));

	m_shader.bind();
	m_shader.updateUniform(m_transform.getTransform(), m_transform.getProjectedTransform(), m_material);

	m_mesh.draw();
}

Game::Game() 
	: m_material(ResourceLoader::loadTexture("default.png"), sf::Vector3f(1, 1, 1))
{
	m_mesh = Mesh();
	m_shader = PhongShader();
	m_shader.setAmbientLight(sf::Vector3f(.1f, .1f, .1f));
	m_shader.setDirectionalLight(DirectionalLight(BaseLight(sf::Vector3f(1, 1, 1), 0.8f), sf::Vector3f(1, 1, 1)));

	//ResourceLoader::loadMesh("cube2.obj", m_mesh);
	//ResourceLoader::loadMesh("monkey.obj", m_mesh);

	std::vector<Vertex> vertices{
		Vertex(sf::Vector3f(-1, -1, 0.5773), sf::Vector2f(0.0, 0.0)),
		Vertex(sf::Vector3f(0, -1, -1.15475), sf::Vector2f(0.5, 0.0)),
		Vertex(sf::Vector3f(1, -1, 0.5773), sf::Vector2f(1, 0)),
		Vertex(sf::Vector3f(0, 1, 0), sf::Vector2f(0.5, 1.0)),
	};

	std::vector<int> indices{
		0, 3, 1,
		1, 3, 2,
		2, 3, 0,
		1, 2, 0
		};

	//std::vector<Vertex> vertices{
	//	Vertex(sf::Vector3f(-1, -1, 0), sf::Vector2f(0.0, 0.0)),
	//	Vertex(sf::Vector3f(-1, 1, 0), sf::Vector2f(1.0, 0.0)),
	//	Vertex(sf::Vector3f(1, 1, 0), sf::Vector2f(1.0, 1.0)),
	//	Vertex(sf::Vector3f(1, -1, 0), sf::Vector2f(1, 0.0)),
	//};

	//std::vector<int> indices{
	//	0, 1, 3,
	//	1, 2, 3
	//};

	m_mesh.addVertices(&vertices[0], vertices.size(), &indices[0], indices.size(), true);



	m_transform.setProjection(constants::FOV, constants::WIDTH, constants::HEIGHT, constants::ZNEAR, constants::ZFAR);
	m_transform.setCamera(&m_camera);
}


Game::~Game()
{
}
