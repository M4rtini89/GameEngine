#pragma once
#include <string>
#include <map>
#include "SFML\System\Vector3.hpp"
#include "Matrix4f.h"

class Shader
{
private:
	int m_program;
	std::map<std::string, int> m_uniforms;

	void addProgram(std::string, int type);
public:

	void addUniform(std::string uniform);
	void addVertexShader(std::string text);
	void addGeometryShader(std::string text);
	void addFragmentShader(std::string text);
	void compileShader();
	void bind();

	void setUniformi(std::string uniformName, int value);
	void setUniformf(std::string uniformName, float value);
	void setUniform(std::string uniformName, sf::Vector3f value);
	void setUniform(std::string uniformName, Matrix4f value);

	void updateUniform(Matrix4f worldMatrix, Matrix4f projectedMatrix);

	Shader();
	~Shader();
};

