#include "Mesh.h"
#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include "Vertex.h"



void Mesh::addVertices(Vertex* vertices, int vertSize, int* indexes, int indexSize)
{
	if (!m_vbo) glGenBuffers(1, &m_vbo);
	if (!m_ibo) glGenBuffers(1, &m_ibo);
	m_size = indexSize;

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, vertSize * sizeof(Vertex), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ARRAY_BUFFER, indexSize * sizeof(int), indexes, GL_STATIC_DRAW);



}

void Mesh::draw() const
{
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)sizeof(sf::Vector3f));
	//glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glDrawElements(GL_TRIANGLES, m_size, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

}

Mesh::Mesh()
{
	m_vbo = 0;
	m_size = 0;
}


Mesh::~Mesh()
{
	if (m_vbo) glDeleteBuffers(1, &m_vbo);
}
