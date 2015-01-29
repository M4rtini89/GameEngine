#include "PhongShader.h"
#include "Shader.h"
#include "ResourceLoader.h"
#include "Material.h"
#include "RenderUtil.h"

DirectionalLight PhongShader::m_directionalLight = DirectionalLight(BaseLight(sf::Vector3f(0, 0, 0), 0), sf::Vector3f(0, 0, 0));

sf::Vector3f PhongShader::m_ambientLight = sf::Vector3f(.1f, .1f, .1f);


PhongShader::PhongShader() : Shader()
{
	addVertexShader(ResourceLoader::loadShader("phongVertex.vs"));
	addFragmentShader(ResourceLoader::loadShader("phongFragment.fs"));
	compileShader();

	addUniform("transform");
	addUniform("transformProjected");
	addUniform("ambientLight");
	addUniform("baseColor");

	addUniform("directionalLight.base.color");
	addUniform("directionalLight.base.intensity");
	addUniform("directionalLight.direction");
}


PhongShader::~PhongShader()
{
}

void PhongShader::updateUniform(Matrix4f worldMatrix, Matrix4f projectedMatrix, Material material)
{
	if (material.getTexture().getId() != 0)
	{
		material.getTexture().bind();
	}
	else
	{
		RenderUtil::unbindTextures();
	}
	setUniform("transformProjected", projectedMatrix);
	setUniform("transform", worldMatrix);
	setUniform("baseColor", material.getColor());
	setUniform("ambientLight", m_ambientLight);

	//setUniform("directionalLigth", m_directionalLight);
	setUniform("directionalLight.direction", m_directionalLight.direction);
	setUniform("directionalLight.base.color", m_directionalLight.base.color);
	setUniformf("directionalLight.base.intensity", m_directionalLight.base.intensity);
}

//void PhongShader::setUniform(std::string uniformName, BaseLight baseLight)
//{
//	setUniform(uniformName + ".color", baseLight.getColor());
//	setUniformf(uniformName + ".intensity", baseLight.getIntensity());
//}
//
//void PhongShader::setUniform(std::string uniformName, DirectionalLight directionalLight)
//{
//	setUniform(uniformName + ".base", directionalLight.getBase());
//	//setUniform(uniformName + ".direction", directionalLight.getDirection());
//	setUniform("directionalLight.direction", sf::Vector3f(1, 0, 0));
//
//}


