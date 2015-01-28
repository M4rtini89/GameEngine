#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include <iostream>

#include "constants.h"

#include "Window.h"
#include "MainComponent.h"

#include "ResourceLoader.h"


int main()
{
	MainComponent game(Window::createDisplay());

	sf::ContextSettings settings = game.getContextSettings();

	std::cout << "depth bits:" << settings.depthBits << std::endl;
	std::cout << "stencil bits:" << settings.stencilBits << std::endl;
	std::cout << "antialiasing level:" << settings.antialiasingLevel << std::endl;
	std::cout << "version:" << settings.majorVersion << "." << settings.minorVersion << std::endl;


	game.start();

	return 0;
}