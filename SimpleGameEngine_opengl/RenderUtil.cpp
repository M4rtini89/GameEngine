#include "RenderUtil.h"
//#include <SFML/OpenGL.hpp>

#include <GL/glew.h>
#include <iostream>

void RenderUtil::clearScreen()
{
	//TODO : Stencil Buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderUtil::initGraphics()
{
	glClearColor(0, 0, 0, 0.0);

	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	//TODO DEPTH clamp for later

	//glEnable(GL_FRAMEBUFFER_SRGB);
	//glEnable(GL_ARB_framebuffer_sRGB);
}

std::string RenderUtil::getOpenGLVersion()
{
	return (char*)glGetString(GL_VERSION);
}

void RenderUtil::setTextures(bool enabled)
{
	if (enabled)
		glEnable(GL_TEXTURE_2D);
	else
		glDisable(GL_TEXTURE_2D);
}

void RenderUtil::setClearColor(sf::Vector3f color)
{
	glClearColor(color.x, color.y, color.z, 1.f);
}

void RenderUtil::unbindTextures()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

