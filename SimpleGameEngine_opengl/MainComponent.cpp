#include "MainComponent.h"

#include <SFML/Window.hpp>
//#include <SFML/OpenGL.hpp>
#include <GL/glew.h>

#include <iostream>
#include <string>

#include "Window.h"
#include "constants.h"
#include "RenderUtil.h"

void MainComponent::render()
{
	RenderUtil::clearScreen();
	m_game.render();
	Window::render(m_window);
}

void MainComponent::start()
{
	if (m_isRunning)
		return;

	run();
}

void MainComponent::stop()
{
	if (!m_isRunning)
		return;
	m_isRunning = false;
}

void MainComponent::run()
{
	int frames = 0;
	sf::Time frameCounter = sf::Time::Zero;
	m_isRunning = true;
	bool timeToRender = false;

	const sf::Time frameTime = sf::seconds(1.0) / constants::FRAME_CAP;

	sf::Clock clock;
	sf::Time unprocessedTime = sf::Time::Zero;

	while (m_isRunning)
	{
		sf::Event event;
		sf::Time passedTime = clock.restart();

		unprocessedTime += passedTime;
		frameCounter += passedTime;
		while (unprocessedTime >= frameTime)
		{
			timeToRender = true;
			unprocessedTime -= frameTime;

			//Event handling and user input
			while (m_window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					stop();
				else if (event.type == sf::Event::Resized)
				{
					glViewport(0, 0, event.size.width, event.size.height);
				}
				
				//keyboard and mouse input
				Input::update();

				m_game.input();
			}

			//Update game
			m_game.update(frameTime.asSeconds());
			if (frameCounter.asSeconds() >= 1.0)
			{
				std::cout << frames << std::endl;
				frames = 0;
				frameCounter = sf::seconds(0.0);
			}
		}

		//Render game
		if (timeToRender)
		{
			m_game.render();
			render();
			frames++;
		}
		else
		{
			sf::sleep(sf::milliseconds(1));
		}


	}
}

sf::ContextSettings MainComponent::getContextSettings() const
{
	return m_window->getSettings();
}

MainComponent::MainComponent(sf::Window* window)
{
	std::cout << "Current OpenGL version: " << RenderUtil::getOpenGLVersion() << std::endl;
	RenderUtil::initGraphics();
	m_isRunning = false;
	m_window = window;
}

MainComponent::~MainComponent()
{
	delete m_window;
}

sf::Window* MainComponent::m_window;
