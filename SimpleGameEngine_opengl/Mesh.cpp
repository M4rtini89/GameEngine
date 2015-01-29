#include "Mesh.h"
#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include "Vertex.h"
#include "Vector.h"



void Mesh::addVertices(Vertex* vertices, int vertSize, int* indexes, int indexSize, bool calcNormals)
{
	if (!m_vbo) glGenBuffers(1, &m_vbo);
	if (!m_ibo) glGenBuffers(1, &m_ibo);
	m_size = indexSize;
	
	if (calcNormals)
		CalcNormals(vertices, vertSize, indexes, indexSize);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, vertSize * sizeof(Vertex), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ARRAY_BUFFER, indexSize * sizeof(int), indexes, GL_STATIC_DRAW);



}

void Mesh::draw() const
{
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)sizeof(sf::Vector3f));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(sf::Vector3f) + sizeof(sf::Vector2f)));
	//glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glDrawElements(GL_TRIANGLES, m_size, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

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


void Mesh::CalcNormals(Vertex* vertices, int vertSize, int* indices, int indexSize)
{
	for (int i = 0; i < indexSize; i += 3)
	{
		int i0 = indices[i];
		int i1 = indices[i + 1];
		int i2 = indices[i + 2];

		sf::Vector3f v1 = vertices[i1].pos - vertices[i0].pos;
		sf::Vector3f v2 = vertices[i2].pos - vertices[i0].pos;

		sf::Vector3f normal = Vector::normalized(Vector::cross(v1, v2));

		vertices[i0].normal += normal;
		vertices[i1].normal += normal;
		vertices[i2].normal += normal;

	}
	for (int i = 0; i < vertSize; ++i)
	{
		vertices[i].normal = (Vector::normalized(vertices[i].normal));
	}
}

