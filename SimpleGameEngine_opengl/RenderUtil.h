#pragma once

#include <string>
#include "SFML\System\Vector3.hpp"

class RenderUtil
{
public:
	static void clearScreen();
	static void initGraphics();
	static void setTextures(bool enabled);
	static void setClearColor(sf::Vector3f);
	static std::string getOpenGLVersion();
	static void unbindTextures();
};

