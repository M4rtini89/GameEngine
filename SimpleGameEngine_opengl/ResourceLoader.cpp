#include "ResourceLoader.h"
#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include <fstream>
#include <streambuf>
#include "Mesh.h"
#include <vector>
#include <string>
#include "Vertex.h"
#include "SFML\System\Vector3.hpp"
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


std::string ResourceLoader::loadShader(std::string fileName)
{
	std::ifstream in("./res/shaders/" + fileName, std::ios::in | std::ios::binary);
	if (in.good())
	{
		return(std::string(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>()));
		
	}
	fprintf(stderr, "file not found (%s)", fileName);
	exit(1);
}

void ResourceLoader::loadMesh(std::string fileName, Mesh & mesh)
{
	std::ifstream in("./res/models/" + fileName, std::ios::in | std::ios::binary);
	std::string line;
	std::vector<Vertex> verticies;
	std::vector<int> indecies; 

	while (getline(in, line))
	{
		std::vector<std::string> tokens;
		tokenize(line, tokens);
		if (tokens[0] == "#" || tokens.size() == 0)
			continue;
		else if (tokens[0] == "v")
		{
			float x = stof(tokens[1]);
			float y = stof(tokens[2]);
			float z = stof(tokens[3]);
			verticies.push_back(Vertex(sf::Vector3f(x, y, z)));
			//std::cout << "v: " << x << " " << y << " " << z << std::endl;
		}
		else if (tokens[0] == "f" && tokens.size() >  1)
		{
			std::vector<std::string> subTokens;
			subTokens.reserve(3);
			for (int i = 1; i < tokens.size(); ++i)
			{
				subTokens.clear();
				tokenize(tokens[i], subTokens, "/", false);
				int index = stoi(subTokens[0]) - 1;
				indecies.push_back(index);
			}
			//int i1 = stoi(tokens[1]) - 1;
			//int i2 = stoi(tokens[2]) - 1;
			//int i3 = stoi(tokens[3]) - 1;
			//indecies.push_back(i1);
			//indecies.push_back(i2);
			//indecies.push_back(i3);
			//std::cout << "f: " << i1 << " " << i2 << " " << i3 << std::endl;
		}


	}
	//std::vector<Vertex> vertices;
	//vertices.push_back(Vertex(sf::Vector3f(-1, -1, 0)));
	//vertices.push_back(Vertex(sf::Vector3f(0, 1, 0)));
	//vertices.push_back(Vertex(sf::Vector3f(1, -1, 0)));
	//vertices.push_back(Vertex(sf::Vector3f(0, -1, 1)));

	//std::vector<int> indexes{   0, 1, 3,
	//							3, 1, 2,
	//							2, 1, 0,
	//							0, 3, 2};


	//mesh.addVertices(&vertices[0], vertices.size(), &indexes[0], indexes.size());

	
	mesh.addVertices(&verticies[0], verticies.size(), &indecies[0], indecies.size());
	return;
}

Texture ResourceLoader::loadTexture(std::string filename)
{
	int width, height, bytesPerPixel;
	unsigned char* data = stbi_load(("./res/textures/" + filename).c_str(), &width, &height, &bytesPerPixel, 4);

	if(data == nullptr)
	{
		std::cerr << "Unable to load texture: " << filename << std::endl;
	}

	GLenum textureTarget = GL_TEXTURE_2D;
	GLfloat filter = GL_NEAREST;
	unsigned int textureId; 

	if (width > 0 && height > 0 && data != 0)
	{
		glGenTextures(1, &textureId);
		glBindTexture(textureTarget, textureId);
		glTexParameterf(textureTarget, GL_TEXTURE_MIN_FILTER, filter);
		glTexParameterf(textureTarget, GL_TEXTURE_MAG_FILTER, filter);
		glTexImage2D(textureTarget, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	}
	else
	{
		textureId = 0;
	}

	return Texture(textureId);

}
