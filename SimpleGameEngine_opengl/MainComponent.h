#pragma once
#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Game.h"
#include "Input.h"

class MainComponent
{
private:
	static sf::Window* m_window;
	bool m_isRunning;
	Game m_game;

	void run();
	void render();

public:

	void start();
	void stop();

	sf::ContextSettings getContextSettings() const;

	static sf::Window* const getWindow() { return m_window; }
	MainComponent(sf::Window* window);
	~MainComponent();
};

