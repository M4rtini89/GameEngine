#pragma once
#include "Shader.h"
#include "Matrix4f.h"
#include "Material.h"

class BasicShader : public Shader
{
public:
	void updateUniform(Matrix4f worldMatrix, Matrix4f projectedMatrix, Material material);
	BasicShader();
	~BasicShader();
};

