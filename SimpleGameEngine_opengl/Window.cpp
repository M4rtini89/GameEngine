#include "Window.h"
#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

sf::Window* Window::createDisplay(const int width /*= constants::WIDTH*/, const int height /*= constants::HEIGHT*/, std::string title /*= constants::TITLE*/)
{
	sf::ContextSettings contextSetting;
	contextSetting.majorVersion = constants::OPENGL_MAJOR;
	contextSetting.minorVersion = constants::OPENGL_MINOR;

	sf::Window* window = new sf::Window(sf::VideoMode(constants::WIDTH, constants::HEIGHT), constants::TITLE, sf::Style::Default, contextSetting);

	window->setVerticalSyncEnabled(constants::V_SYNCH);

	glewExperimental = GL_TRUE;
	glewInit();

	return window;

}

void Window::render(sf::Window* window)
{
	//Swap back and front buffers
	window->display();
}
