#pragma once

#include <string>
#include "Mesh.h"
#include "Texture.h"

class ResourceLoader
{
public:

	static std::string loadShader(std::string fileName);
	static void loadMesh(std::string fileName, Mesh& mesh);
	static Texture loadTexture(std::string filename);
	ResourceLoader();
	~ResourceLoader();
};


//http://stackoverflow.com/questions/236129/split-a-string-in-c

template < class ContainerT >
void tokenize(const std::string& str, ContainerT& tokens,
	const std::string& delimiters = " ", bool trimEmpty = true)
{
	std::string::size_type pos, lastPos = 0;

	using value_type = typename ContainerT::value_type;
	using size_type = typename ContainerT::size_type;

	while (true)
	{
		pos = str.find_first_of(delimiters, lastPos);
		if (pos == std::string::npos)
		{
			pos = str.length();

			if (pos != lastPos || !trimEmpty)
				tokens.push_back(value_type(str.data() + lastPos,
				(size_type)pos - lastPos));

			break;
		}
		else
		{
			if (pos != lastPos || !trimEmpty)
				tokens.push_back(value_type(str.data() + lastPos,
				(size_type)pos - lastPos));
		}

		lastPos = pos + 1;
	}
}