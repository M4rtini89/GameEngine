#include "Texture.h"
#include <GL/glew.h>
#include <SFML/OpenGL.hpp>

void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, m_id);
}