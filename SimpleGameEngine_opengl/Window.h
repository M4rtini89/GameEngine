#pragma once

#include "constants.h"

namespace sf
{
	class Window;
}

class Window
{
public:
	static sf::Window* createDisplay(const int width = constants::WIDTH, const int height = constants::HEIGHT, std::string title = constants::TITLE);
	static void render(sf::Window* window);
};

