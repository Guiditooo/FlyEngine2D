#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>

#include "Exports.h"
#include "KeyCode/KeyCode.h"

namespace FlyEngine
{
	class Window;
	class Renderer;

	namespace Entities
	{
		class Entity;
		class Rectangle;
		class Triangle;
		class Sprite;
	}
	namespace Utils
	{
		struct Buffers;
		struct VertexAttribute;
	}
	/*
	enum class EntityType
	{
		Triangle,
		Rectangle,
		Sprite
	};

	enum class MovementDirection
	{
		Up,
		Right,
		FreeMovement
	};
	*/

	class FLY_API BaseGame
	{
	public:
		BaseGame();
		~BaseGame();

		bool IsEngineRunning();
		void SetWindowParameters(int width, int height, std::string name = "FlyEngine");

		//int CreateEntity(EntityType entityType, float posX, float posY, float width, float height);
		//bool MoveEntity(int id, MovementDirection movementDirection, int amount, float x, float y, float /z);
		//bool ScaleEntity(int id, int amount);
		//bool RotateEntity(int id, int amount);

		Entities::Rectangle* CreateRectangle(float posX, float posY, float posZ, float width, float height);
		Entities::Rectangle* CreateRectangle(float posX, float posY, float posZ, float width);
		Entities::Triangle* CreateTriangle(float posX, float posY, float posZ, float base, float height);

		//int CreateRectangle(float posX, float posY, float posZ, float width, float height);
		//int CreateRectangle(float posX, float posY, float posZ, float width);
		//int CreateTriangle(float posX, float posY, float posZ, float base, float height);

	private:
		std::unordered_map<int, Entities::Entity*> entityList;  // Mapa de ID a Entidad*
		int nextID = 0;

		Renderer* renderer;
		bool isRunning;

		bool checkEsc;

		void InternalInit();
		void InternalInput();
		void InternalUpdate();
		void InternalDraw();
		void InternalDeinit();

		void DrawObjects();
		void SwapBuffers();

		void SetUpOpenGlFunctions();

		void CreateBuffers(Utils::Buffers* buffers);
		void BindBuffers(Utils::Buffers* buffers, std::vector<float> vertex, std::vector<unsigned int> index);
		void SetVertexAttributes(std::vector<Utils::VertexAttribute> vertexAttributes);

		void SetMatrixUniforms(Entities::Entity* entity);
		void SetMaterialUniforms(Entities::Entity* entity);

		int AssingEntityID(Entities::Entity* entity);
		Entities::Entity* EntityExists(int id);



		float PixelsToEngine(int objectWidthInPixels, float windowDimension);

	protected:
		Window* window;

		std::string initialWindowName;
		int initialWindowWidth;
		int initialWindowHeight;

		void RunEngine();

		bool GetKeyDown(Utils::KeyCode key);
		bool GetKeyUp(Utils::KeyCode key);
		bool GetKeyPressed(Utils::KeyCode key);

		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void Deinit() = 0;


	};
}