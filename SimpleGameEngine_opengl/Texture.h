#pragma once
class Texture
{
private:
	int m_id;

public:
	int getId()const { return m_id; }
	void bind();
	Texture(int id) : m_id(id){};
	Texture() : m_id(0){};
};


