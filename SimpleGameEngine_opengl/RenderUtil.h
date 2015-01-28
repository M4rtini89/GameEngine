#pragma once

#include <string>

class RenderUtil
{
public:
	static void clearScreen();
	static void initGraphics();
	static void setTextures(bool enabled);
	static std::string getOpenGLVersion();
};

