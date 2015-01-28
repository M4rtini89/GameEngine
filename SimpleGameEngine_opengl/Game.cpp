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
	m_camera.input(dt);
	temp_ += dt;
	float sinTemp = std::sin(temp_);
	m_transform.setTranslate(0, 0, 5);
	m_transform.setRotate(0, temp_ * 100, 0);
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
	m_shader = BasicShader();

	//ResourceLoader::loadMesh("cube2.obj", m_mesh);
	//ResourceLoader::loadMesh("monkey.obj", m_mesh);

	std::vector<Vertex> vertices{
		Vertex(sf::Vector3f(-1, -1, 0), sf::Vector2f(0, 0)),
		Vertex(sf::Vector3f(0, 1, 0), sf::Vector2f(0.5, 0)),
		Vertex(sf::Vector3f(1, -1, 0), sf::Vector2f(1, 0)),
		Vertex(sf::Vector3f(0, -1, 1), sf::Vector2f(0, 0.5)),
	};

	std::vector<int> indices{
			3, 1, 0,
			2, 1, 3,
			0, 1, 2,
			0, 2, 3
		};

	m_mesh.addVertices(&vertices[0], vertices.size(), &indices[0], indices.size());



	m_transform.setProjection(constants::FOV, constants::WIDTH, constants::HEIGHT, constants::ZNEAR, constants::ZFAR);
	m_transform.setCamera(&m_camera);
}


Game::~Game()
{
}
