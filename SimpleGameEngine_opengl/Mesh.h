#pragma once
#include "vertex.h"

class Mesh
{
public:
	Mesh();
	virtual ~Mesh();

	void addVertices(Vertex* vertices, int vertSize, int* indexes, int indexSize);
	void draw() const;
private:

	unsigned int m_vbo;
	unsigned int m_ibo;
	int m_size;
};
