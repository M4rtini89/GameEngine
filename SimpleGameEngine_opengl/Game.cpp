#include "Game.h"
#include <iostream>
#include "Input.h"
#include "MainComponent.h"
#include "Mesh.h"
#include "ResourceLoader.h"
#include "Shader.h"
#include "constants.h"

void Game::input()
{
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
	m_shader.bind();
	m_shader.setUniform("transform", m_transform.getProjectedTransform());
	m_texture.bind();
	m_mesh.draw();
}

Game::Game() : m_texture(ResourceLoader::loadTexture("default.png"))
{
	m_mesh = Mesh();
	m_shader = Shader();
	m_shader.addVertexShader(ResourceLoader::loadShader("basicVertex.vs"));
	m_shader.addFragmentShader(ResourceLoader::loadShader("basicFragment.fs"));
	m_shader.compileShader();

	m_shader.addUniform("transform");

	//ResourceLoader::loadMesh("cube2.obj", m_mesh);
	//ResourceLoader::loadMesh("monkey.obj", m_mesh);

	std::vector<Vertex> vertices{
		Vertex(sf::Vector3f(-1, -1, 0), sf::Vector2f(0, 0)),
		Vertex(sf::Vector3f(0, 1, 0), sf::Vector2f(0.5, 0)),
		Vertex(sf::Vector3f(1, -1, 0), sf::Vector2f(1, 0)),
		Vertex(sf::Vector3f(0, -1, 1), sf::Vector2f(0, 0.5)),
	};

	std::vector<int> indices{
			0, 1, 3,
			3, 1, 2,
			2, 1, 0,
			0, 2, 3
		};

	m_mesh.addVertices(&vertices[0], vertices.size(), &indices[0], indices.size());



	m_transform.setProjection(constants::FOV, constants::WIDTH, constants::HEIGHT, constants::ZNEAR, constants::ZFAR);
	m_transform.setCamera(&m_camera);
}


Game::~Game()
{
}
