#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <unordered_map>

#include <glew.h>
#include <glm.hpp>

#include "Shader/Shader.h"

#include "VertexAttribute/VertexAttribute.h"
#include "Color/Color.h"
#include "Buffers/Buffers.h"

namespace FlyEngine
{
	using namespace Utils;

	namespace Entities
	{
		class Entity;
		class Sprite;
	}

	class Renderer
	{
	private:
		Color* bgColor;

	public:
		Renderer();
		~Renderer();

		void DrawObject(Entities::Entity* toDraw);//Pasar a component, porque quizas quiero UI
		void DrawTexture(Entities::Sprite* sprite);

		void UseTextures(GLenum textureType, GLuint textureID);

		void SetBackgroundColor(Color* newBgColor);
		Color* GetBackgroundColor();

		void CreateBaseBuffers(Utils::Buffers& buffers);
		void BindBuffers(Utils::Buffers& buffers, float* vertices, unsigned int vertexSize, unsigned int* index, unsigned int indexSize);
		void BindBuffers(Utils::Buffers& buffers, const std::vector<float>& vertices, unsigned int vertexSize, const std::vector<unsigned int>& index, unsigned int indexSize);

		void SetVertexAttributes(std::vector<Utils::VertexAttribute> vertexAttributes);

		void SetMatrix4Uniform(unsigned int shaderID, const char* variableName, glm::mat4x4 matrix);
		void SetMatrix3Uniform(unsigned int shaderID, const char* variableName, glm::mat3x3 matrix);
		void SetMatrix2Uniform(unsigned int shaderID, const char* variableName, glm::mat2x2 matrix);

		void SetVec4Uniform(unsigned int shaderID, const char* variableName, glm::vec4 vec);
		void SetVec4Uniform(unsigned int shaderID, const char* variableName, float x, float y, float z, float w);

		void SetVec3Uniform(unsigned int shaderID, const char* variableName, glm::vec3 vec);
		void SetVec3Uniform(unsigned int shaderID, const char* variableName, float x, float y, float z);

		void SetVec2Uniform(unsigned int shaderID, const char* variableName, glm::vec2 vec);
		void SetVec2Uniform(unsigned int shaderID, const char* variableName, float x, float y);

		void SetFloatUniform(unsigned int shaderID, const char* variableName, float value);
		void SetBoolUniform(unsigned int shaderID, const char* variableName, bool value);
		void SetIntUniform(unsigned int shaderID, const char* variableName, int value);

		void DrawRequest(Utils::Buffers buffers, unsigned int indexCount);
	};
}

#endif // !RENDERER_H