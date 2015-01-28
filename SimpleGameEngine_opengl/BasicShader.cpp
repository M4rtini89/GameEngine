#include "BasicShader.h"
#include "Shader.h"
#include "ResourceLoader.h"
#include "Material.h"
#include "RenderUtil.h"


BasicShader::BasicShader() : Shader()
{
	addVertexShader(ResourceLoader::loadShader("basicVertex.vs"));
	addFragmentShader(ResourceLoader::loadShader("basicFragment.fs"));
	compileShader();

	addUniform("transform");
	addUniform("color");
}


BasicShader::~BasicShader()
{
}

void BasicShader::updateUniform(Matrix4f worldMatrix, Matrix4f projectedMatrix, Material material)
{
	if (material.getTexture().getId() != 0)
	{
		material.getTexture().bind();
	}
	else
	{
		RenderUtil::unbindTextures();
	}
	setUniform("transform", projectedMatrix);
	setUniform("color", material.getColor());
}
