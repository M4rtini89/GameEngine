#pragma once
#include "Shader.h"
#include "Matrix4f.h"
#include "Material.h"
#include "DirectionalLight.h"

class PhongShader : public Shader
{
private:
	static sf::Vector3f m_ambientLight;
	static DirectionalLight m_directionalLight;
public:
	void updateUniform(Matrix4f worldMatrix, Matrix4f projectedMatrix, Material material);
	PhongShader();
	~PhongShader();

	static sf::Vector3f getAmbientLight() { return m_ambientLight; }
	static void setAmbientLight(sf::Vector3f val) { m_ambientLight = val; }
	static void setDirectionalLight(DirectionalLight directionalLigt) { m_directionalLight = directionalLigt; }
	static DirectionalLight getDirectionalLight() { return m_directionalLight; }
	
	using Shader::setUniform;
	void setUniform(std::string uniformName, DirectionalLight directionalLight);
	void setUniform(std::string uniformName, BaseLight baseLight);
};

