#include "Texture.h"

namespace FlyEngine
{

	Texture::Texture(int textureID, int textureWidth, int textureHeight, const std::string& texturePath)
	{
		id = textureID;
		path = texturePath;
		width = textureWidth;
		height = textureHeight;
		isActive = true;
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, (GLuint*)id);
	}

	/*
	void Texture::Bind(unsigned int slot) const
	{

	}
	void Texture::UnBind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	*/

	void Texture::SetType(std::string type)
	{
		this->type = type; //Normal, Base, Height, etc.
	}

	int Texture::GetID() const
	{
		return id;
	}

	const std::string& Texture::GetPath()
	{
		return path;
	}

	int Texture::GetWidth()
	{
		return width;
	}

	int Texture::GetHeight()
	{
		return height;
	}

	bool Texture::IsActive()
	{
		return isActive;
	}
}