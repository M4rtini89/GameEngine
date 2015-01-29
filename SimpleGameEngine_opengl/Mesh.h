#pragma once
#include "vertex.h"
#include <vector>

class Mesh
{
private:
	void CalcNormals(Vertex* vertices, int vertSize, int* indices, int indexSize);
public:
	Mesh();
	virtual ~Mesh();

	void addVertices(Vertex* vertices, int vertSize, int* indexes, int indexSize, bool calcNormals = true );
	void draw() const;
private:

	unsigned int m_vbo;
	unsigned int m_ibo;
	int m_size;
};
