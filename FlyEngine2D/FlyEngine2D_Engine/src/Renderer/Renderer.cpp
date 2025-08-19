#include "Renderer.h"

#include <vector>
#include <iostream>
#include <string>

#include <glfw3.h>
#include <gtc/type_ptr.hpp>

#include "TextureManager/TextureManager.h"

#include "Entity/Entity.h"
#include "Sprite/Sprite.h"
#include "Material/Material.h"

namespace FlyEngine
{

	Renderer::Renderer()
	{
		bgColor = new Color(COLOR::FLYBLACK);
	}

	Renderer::~Renderer()
	{

	}
	void Renderer::DrawObject(Entities::Entity* toDraw)
	{

	}
	

	void Renderer::DrawTexture(Entities::Sprite* sprite)
	{
		//glActiveTexture(GL_TEXTURE0);
		Managers::TextureManager::BindTexture(sprite->GetTexture());
		SetIntUniform(sprite->GetShaderID(), "theTexture", 0);
		glActiveTexture(GL_TEXTURE0);
	}

	void Renderer::SetBackgroundColor(Color* newBgColor)
	{
		bgColor = newBgColor;
		glm::vec4 bgVector = bgColor->GetColorV4();

		glClearColor(bgVector.r, bgVector.g, bgVector.b, bgVector.a);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	Color* Renderer::GetBackgroundColor()
	{
		return bgColor;
	}

	void Renderer::CreateBaseBuffers(Utils::Buffers& buffers)
	{
		glGenVertexArrays(1, &buffers.VAO);
		glGenBuffers(1, &buffers.VBO);
		glGenBuffers(1, &buffers.EBO);
	}

	void Renderer::BindBuffers(Utils::Buffers& buffers, float* vertices, unsigned int vertexSize, unsigned int* index, unsigned int indexSize)
	{
		glBindVertexArray(buffers.VAO);

		glBindBuffer(GL_ARRAY_BUFFER, buffers.VBO);
		glBufferData(GL_ARRAY_BUFFER, vertexSize, vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers.EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexSize, index, GL_STATIC_DRAW);
	}

	void Renderer::BindBuffers(Utils::Buffers& buffers, const std::vector<float>& vertices, unsigned int vertexSize, const std::vector<unsigned int>& index, unsigned int indexSize)
	{
		glBindVertexArray(buffers.VAO);

		glBindBuffer(GL_ARRAY_BUFFER, buffers.VBO);
		glBufferData(GL_ARRAY_BUFFER, vertexSize * sizeof(float), vertices.data(), GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers.EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexSize * sizeof(float), index.data(), GL_STATIC_DRAW);
	}

	void Renderer::SetVertexAttributes(std::vector<VertexAttribute> vertexAttributes)
	{
		for (short i = 0; i < vertexAttributes.size(); i++)
		{
			unsigned int size = vertexAttributes[i].elementSize;
			unsigned int type = vertexAttributes[i].variableType;
			unsigned int normalized = vertexAttributes[i].isNormalized;
			unsigned int stride = vertexAttributes[i].sizeOfVertex;
			unsigned int offset = vertexAttributes[i].offset;

			glVertexAttribPointer(i, size, type, normalized, stride, (void*)offset);
			glEnableVertexAttribArray(i);
		}
	}

	void Renderer::DrawRequest(Utils::Buffers buffers, unsigned int indexCount)
	{
		glBindVertexArray(buffers.VAO);
		glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}

	void Renderer::UseTextures(GLenum textureType, GLuint textureID)
	{
		glActiveTexture(textureType);
		glBindTexture(GL_TEXTURE_2D, textureID);
		glActiveTexture(GL_TEXTURE0);
	}

	void Renderer::SetMatrix4Uniform(unsigned int shaderID, const GLchar* variableName, glm::mat4x4 matrix)
	{
		GLint modelUniformLocation = glGetUniformLocation(shaderID, variableName);
		glUniformMatrix4fv(modelUniformLocation, 1, GL_FALSE, glm::value_ptr(matrix));
	}

	void Renderer::SetMatrix3Uniform(unsigned int shaderID, const GLchar* variableName, glm::mat3x3 matrix)
	{
		GLint modelUniformLocation = glGetUniformLocation(shaderID, variableName);
		glUniformMatrix3fv(modelUniformLocation, 1, GL_FALSE, glm::value_ptr(matrix));
	}

	void Renderer::SetMatrix2Uniform(unsigned int shaderID, const GLchar* variableName, glm::mat2x2 matrix)
	{
		GLint modelUniformLocation = glGetUniformLocation(shaderID, variableName);
		glUniformMatrix2fv(modelUniformLocation, 1, GL_FALSE, glm::value_ptr(matrix));
	}

	void Renderer::SetVec4Uniform(unsigned int shaderID, const char* variableName, glm::vec4 vec)
	{
		GLint uniformLocation = glGetUniformLocation(shaderID, variableName);
		glUniform4f(uniformLocation, vec.x, vec.y, vec.z, vec.w);
	}

	void Renderer::SetVec4Uniform(unsigned int shaderID, const char* variableName, float x, float y, float z, float w)
	{
		GLint uniformLocation = glGetUniformLocation(shaderID, variableName);
		glUniform4f(uniformLocation, x, y, z, w);
	}

	void Renderer::SetVec3Uniform(unsigned int shaderID, const char* variableName, glm::vec3 vec)
	{
		GLint uniformLocation = glGetUniformLocation(shaderID, variableName);
		glUniform3f(uniformLocation, vec.x, vec.y, vec.z);
	}

	void Renderer::SetVec3Uniform(unsigned int shaderID, const char* variableName, float x, float y, float z)
	{
		GLint uniformLocation = glGetUniformLocation(shaderID, variableName);
		glUniform3f(uniformLocation, x, y, z);
	}

	void Renderer::SetVec2Uniform(unsigned int shaderID, const char* variableName, glm::vec2 vec)
	{
		GLint uniformLocation = glGetUniformLocation(shaderID, variableName);
		glUniform2f(uniformLocation, vec.x, vec.y);
	}

	void Renderer::SetVec2Uniform(unsigned int shaderID, const char* variableName, float x, float y)
	{
		GLint uniformLocation = glGetUniformLocation(shaderID, variableName);
		glUniform2f(uniformLocation, x, y);
	}

	void Renderer::SetFloatUniform(unsigned int shaderID, const char* variableName, float value)
	{
		GLint uniformLocation = glGetUniformLocation(shaderID, variableName);
		glUniform1f(uniformLocation, value);
	}


	void Renderer::SetBoolUniform(unsigned int shaderID, const char* variableName, bool value)
	{
		GLint uniformLocation = glGetUniformLocation(shaderID, variableName);
		glUniform1i(uniformLocation, (int)value);
	}

	void Renderer::SetIntUniform(unsigned int shaderID, const char* variableName, int value)
	{
		GLint uniformLocation = glGetUniformLocation(shaderID, variableName);
		glUniform1i(uniformLocation, (int)value);
	}

}