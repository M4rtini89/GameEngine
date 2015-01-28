#include "Shader.h"
#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include <string>
#include <stdexcept>
#include <vector>

static int CheckShaderError(int shader, int flag, bool isProgram, const std::string& errorMessage);

void Shader::addUniform(std::string uniform)
{
	int uniformLocation = glGetUniformLocation(m_program, uniform.c_str());

	if (uniformLocation == -1)
	{
		fprintf(stderr, "Error: Could not find uniform location");
		exit(1);
	}
	m_uniforms[uniform] = uniformLocation;

}

void Shader::addVertexShader(std::string text)
{
	addProgram(text, GL_VERTEX_SHADER);
}

void Shader::addGeometryShader(std::string text)
{
	addProgram(text, GL_GEOMETRY_SHADER);
}

void Shader::addFragmentShader(std::string text)
{
	addProgram(text, GL_FRAGMENT_SHADER);
}

void Shader::addProgram(std::string text, int type)
{
	int shader = glCreateShader(type);
	if (shader == 0)
	{
		fprintf(stderr, "Shader creation failed: Could not find valid memory location when adding shader");
		exit(1);
	}
	const char *c_str = text.c_str();
	glShaderSource(shader, 1, &c_str, NULL);
	glCompileShader(shader);

	GLint success;
	//success = CheckShaderError(m_program, GL_COMPILE_STATUS, false, "Error compiling shader program");
	//if (!success)
	//	exit(1);
	
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLint maxLength = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(shader, maxLength, &maxLength, &errorLog[0]);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", shader, errorLog);
		exit(1);
	}
	glAttachShader(m_program, shader);
}

Shader::Shader()
{
	m_program = glCreateProgram();

	if (m_program == 0)
	{
		fprintf(stderr, "Shader creation failed: Could not find valid memory location in constructor");
		exit(1);
	}
}


Shader::~Shader()
{
}

void Shader::compileShader()
{
	glLinkProgram(m_program);
	CheckShaderError(m_program, GL_LINK_STATUS, true, "Error linking shader program");

	glValidateProgram(m_program);
	CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "Invalid shader program");

}

void Shader::bind()
{
	glUseProgram(m_program);
}

void Shader::setUniformi(std::string uniformName, int value)
{
	glUniform1i(m_uniforms[uniformName], value);
}

void Shader::setUniformf(std::string uniformName, float value)
{
	glUniform1f(m_uniforms[uniformName], value);
}

void Shader::setUniform(std::string uniformName, sf::Vector3f value)
{
	glUniform3f(m_uniforms[uniformName], value.x, value.y, value.z);
}

void Shader::setUniform(std::string uniformName, Matrix4f value)
{
	//float test[4][4] = { { 1, 0, 0, 0.2 }, { 0, 1, 0, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 1 } };
	const float* p = value.raw_pointer();
	glUniformMatrix4fv(m_uniforms[uniformName],1, true, p);
}

void Shader::updateUniform(Matrix4f worldMatrix, Matrix4f projectedMatrix)
{

}

static int CheckShaderError(int shader, int flag, bool isProgram, const std::string& errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if (!success)
	{
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		fprintf(stderr, "%s: '%s'\n", errorMessage.c_str(), error);
	}
	return success;
}