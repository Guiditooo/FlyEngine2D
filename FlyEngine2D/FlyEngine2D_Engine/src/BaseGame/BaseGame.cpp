#include "BaseGame.h"

#include <iostream>

#include "TextureImporter/TextureImporter.h"

#include "Debugger/Debugger.h"

#include "TextureManager/TextureManager.h"
#include "ShaderManager/ShaderManager.h"
#include "MaterialManager/MaterialManager.h"

#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "Timer/Timer.h"
#include "Input/Input.h"

#include "Rectangle/Rectangle.h"
#include "Triangle/Triangle.h"

namespace FlyEngine
{
	using namespace Utils;
	using namespace Entities;

	void FrameBufferResizeCallback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	BaseGame::BaseGame()
	{
		initialWindowName = "FlyEngine";
		initialWindowWidth = 0;
		initialWindowHeight = 0;
		checkEsc = true;

		isRunning = false;

		renderer = nullptr;
		window = nullptr;
		

		Importers::TextureImporter::Init(true);
	}

	BaseGame::~BaseGame()
	{
		if (window != nullptr)
			delete window;
		window = nullptr;

		if (renderer != nullptr)
			delete renderer;
		renderer = nullptr;
	}

	bool BaseGame::IsEngineRunning()
	{
		return isRunning;
	}

	void BaseGame::SetWindowParameters(int width, int height, std::string name)
	{
		initialWindowWidth = width;
		initialWindowHeight = height;
		initialWindowName = name;
	}
	/*
	int BaseGame::CreateEntity(EntityType entityType, float posX, float posY, float width, float height)
	{
		int id = -1;

		switch (entityType)
		{
		case FlyEngine::EntityType::Triangle:
			id = CreateTriangle(posX, posY, 0, width, height);
			break;
		case FlyEngine::EntityType::Rectangle:
			id = CreateRectangle(posX, posY, 0, width, height);
			break;
		case FlyEngine::EntityType::Sprite:
			break;
		default:
			break;
		}
		
		return id;
	}

	bool BaseGame::MoveEntity(int id, MovementDirection movementDirection, int amount, float x, float y, float z)
	{
		Entity* e = EntityExists(id);
		if (e == nullptr)
			return false;

		switch (movementDirection)
		{
		case FlyEngine::MovementDirection::Up:
			e->MoveUp(amount);
			break;
		case FlyEngine::MovementDirection::Right:
			e->MoveRight(amount);
			break;
		case FlyEngine::MovementDirection::FreeMovement:
			e->GetTransform()->WorldTranslate(x * amount, y * amount, z * amount);
			break;
		default:
			break;
		}
		return true;
	}

	bool BaseGame::ScaleEntity(int id, int amount)
	{
		Entity* e = EntityExists(id);
		if (e == nullptr)
			return false;

		e->GetTransform()->WorldScale(amount, amount, amount);

		return true;
	}

	bool BaseGame::RotateEntity(int id, int amount)
	{
		Entity* e = EntityExists(id);
		if (e == nullptr)
			return false;

		e->GetTransform()->WorldRotate(0, 0, amount);

		return true;
	}
	*/

	Rectangle* BaseGame::CreateRectangle(float posX, float posY, float posZ, float width, float height)
	{
		Entities::Rectangle* rec = new Entities::Rectangle();
		glm::vec2 windowSize = window->GetWindowSize();

		rec->GetTransform()->SetWorldPosition(PixelsToEngine(posX, windowSize.x), PixelsToEngine(posY, windowSize.x), PixelsToEngine(posZ, windowSize.x));
		rec->GetTransform()->SetWorldScale(PixelsToEngine(width, windowSize.x), PixelsToEngine(height, windowSize.x), 1);

		rec->SetMaterial(Managers::MaterialManager::GetDefaultBasicMaterial(), false);

		CreateBuffers(rec->GetBuffers());
		BindBuffers(rec->GetBuffers(), rec->GetVertexList(), rec->GetIndexList());
		SetVertexAttributes(rec->GetVertexAttributes());

		AssingEntityID(rec);

		return rec;
	}

	Rectangle* BaseGame::CreateRectangle(float posX, float posY, float posZ, float width)
	{
		return CreateRectangle(posX, posY, posZ, width, width);
	}

	Triangle* BaseGame::CreateTriangle(float posX, float posY, float posZ, float base, float height)
	{
		Entities::Triangle* tri = new Entities::Triangle();
		glm::vec2 windowSize = window->GetWindowSize();

		tri->GetTransform()->SetWorldPosition(PixelsToEngine(posX, windowSize.x), PixelsToEngine(posY, windowSize.x), PixelsToEngine(posZ, windowSize.x));
		tri->GetTransform()->SetWorldScale(PixelsToEngine(base, windowSize.x), PixelsToEngine(height, windowSize.x), 1);

		tri->SetMaterial(Managers::MaterialManager::GetDefaultBasicMaterial(), false);

		CreateBuffers(tri->GetBuffers());
		BindBuffers(tri->GetBuffers(), tri->GetVertexList(), tri->GetIndexList());
		SetVertexAttributes(tri->GetVertexAttributes());

		AssingEntityID(tri);

		return tri;
	}

	/* Entity como ID
	int BaseGame::CreateRectangle(float posX, float posY, float posZ, float width, float height)
	{
		Entities::Rectangle* rec = new Entities::Rectangle();
		glm::vec2 windowSize = window->GetWindowSize();

		rec->GetTransform()->SetWorldPosition(PixelsToEngine(posX, windowSize.x), PixelsToEngine(posY, windowSize.x), PixelsToEngine(posZ, windowSize.x));
		rec->GetTransform()->SetWorldScale(PixelsToEngine(width, windowSize.x), PixelsToEngine(height, windowSize.x), 1);

		rec->SetMaterial(Managers::MaterialManager::GetDefaultBasicMaterial(), false);

		CreateBuffers(rec->GetBuffers());
		BindBuffers(rec->GetBuffers(), rec->GetVertexList(), rec->GetIndexList());
		SetVertexAttributes(rec->GetVertexAttributes());

		rec->SetColor(COLOR::RED);

		return AssingEntityID(rec);
	}

	int BaseGame::CreateRectangle(float posX, float posY, float posZ, float width)
	{
		return CreateRectangle(posX, posY, posZ, width, width);
	}

	int BaseGame::CreateTriangle(float posX, float posY, float posZ, float base, float height)
	{
		Entities::Triangle* tri = new Entities::Triangle();
		glm::vec2 windowSize = window->GetWindowSize();

		tri->GetTransform()->SetWorldPosition(PixelsToEngine(posX, windowSize.x), PixelsToEngine(posY, windowSize.x), PixelsToEngine(posZ, windowSize.x));
		tri->GetTransform()->SetWorldScale(PixelsToEngine(base, windowSize.x), PixelsToEngine(height, windowSize.x), 1);

		tri->SetMaterial(Managers::MaterialManager::GetDefaultBasicMaterial(), false);

		CreateBuffers(tri->GetBuffers());
		BindBuffers(tri->GetBuffers(), tri->GetVertexList(), tri->GetIndexList());
		SetVertexAttributes(tri->GetVertexAttributes());

		return AssingEntityID(tri);
	}

	*/

	void BaseGame::InternalInit()
	{
		Debugger::ConsoleMessage("Starting Fly Engine.", 2, 0, 1, 0);

		if (glfwInit() == GLFW_FALSE)
		{
			Debugger::ConsoleMessage("Error on GLFW initializating", 2, 0, 1, 0);
			Debugger::ConsoleMessage("Stopping execution!", 2, 0, 1, 0);
			return;
		}
		else
		{
			Debugger::ConsoleMessage("GLFW Loaded Successfully", 2, 0, 1, 2);
		}

		if (initialWindowHeight < 0 || initialWindowWidth < 0)
		{
			window = new Window(initialWindowName);
		}
		else
		{
			window = new Window(initialWindowWidth, initialWindowHeight, initialWindowName);
		}
		if (!window)
		{
			Debugger::ConsoleMessage("Error: Window Not Found", 2, 0, 1, 0);
			return;
		}


		SetUpOpenGlFunctions();

		Managers::TextureManager::InitializeManager();
		Managers::ShaderManager::InitializeManager();
		Managers::MaterialManager::InitializeManager();

		renderer = new Renderer();

		Timer::InitTimer({ Timer::Window, Timer::Total, Timer::Delta });
		Timer::EnablePrintMessages(true);

		Input::SetContextWindow(window);

		isRunning = true;

		Init();
	}

	void BaseGame::InternalInput()
	{
		glfwPollEvents();
		Input::Update();
	}

	void BaseGame::InternalUpdate()
	{
		renderer->SetBackgroundColor(Color::GetColor(FlyEngine::COLOR::MOSS_GREEN));

		if (checkEsc)
		{
			if (Input::GetKeyPressed(KeyCode::KEY_ESCAPE))
			{
				isRunning = false;
			}
		}

		Update();

		Timer::UpdateTimer();
	}

	void BaseGame::InternalDraw()
	{
		DrawObjects();
		SwapBuffers();
	}

	void BaseGame::InternalDeinit()
	{
		Deinit();

		glfwSetWindowShouldClose((window->GetWindow()), true);

		glfwTerminate();

		FlyEngine::Debugger::ConsoleMessage("Ending Fly Engine.", 2, 0, 1, 0);
	}

	void BaseGame::DrawObjects()
	{
		for (const auto& par : entityList)
		{
			Entity* entity = par.second;

			if (entity->IsActive() && !entity->IsCameraTarget())
			{
				entity->UseShader();
				SetMatrixUniforms(entity);

				SetMaterialUniforms(entity);

				renderer->SetVec3Uniform(entity->GetShaderID(), "baseColor", entity->GetMaterial()->GetColorV3());
				renderer->SetVec3Uniform(entity->GetShaderID(), "entityColor", entity->GetColorV3());

				renderer->DrawRequest(*(entity->GetBuffers()), entity->GetIndexCount());
			}
		}
	}

	void BaseGame::SwapBuffers()
	{
		glfwSwapBuffers(window->GetWindow());
	}

	void BaseGame::SetUpOpenGlFunctions()
	{
		// Configuración básica de GLFW (necesaria siempre)
		glfwMakeContextCurrent(window->GetWindow());
		glfwSetFramebufferSizeCallback(window->GetWindow(), FrameBufferResizeCallback);

		// Inicialización de GLEW (siempre necesaria)
		if (glewInit() != GLEW_OK)
			Debugger::ConsoleMessage("GLEW FAILED!", 2, 0, 1, 1);

		// Configuración de transparencia (alpha blending) para sprites 2D
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		// Opcional: Alpha testing (para descartar píxeles con alpha bajo)
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1f);

		// Opcional: Mejora de bordes suaves en sprites (antialiasing)
		glEnable(GL_SAMPLE_ALPHA_TO_COVERAGE);
		// glEnable(GL_SAMPLE_ALPHA_TO_ONE);  // Menos común
	}

	void BaseGame::CreateBuffers(Buffers* buffers)
	{
		renderer->CreateBaseBuffers(*buffers);
	}

	void BaseGame::BindBuffers(Buffers* buffers, std::vector<float> vertex, std::vector<unsigned int> index)
	{
		renderer->BindBuffers(*buffers, vertex, vertex.size(), index, index.size());
	}

	void BaseGame::SetVertexAttributes(std::vector<VertexAttribute> vertexAttributes)
	{
		renderer->SetVertexAttributes(vertexAttributes);
	}

	void BaseGame::SetMatrixUniforms(Entities::Entity* entity)
	{
		unsigned int id = entity->GetShaderID();
		renderer->SetMatrix4Uniform(id, "view", glm::mat4());
		renderer->SetMatrix4Uniform(id, "projection", glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f));
		renderer->SetMatrix4Uniform(id, "model", entity->GetModelMatrix());
		renderer->SetVec3Uniform(id, "viewPos", glm::vec3());
	}

	void BaseGame::SetMaterialUniforms(Entities::Entity* entity)
	{
		unsigned int id = entity->GetShaderID();
		Materials::Material* mat = entity->GetMaterial();

		mat->ApplyTextures();
		
		renderer->SetIntUniform(id, "material.diffuse", 0); //Cambiar a auto por material
		
		if (mat->AllowLights())
		{
			renderer->SetIntUniform(id, "material.specular", 1);
			renderer->SetFloatUniform(id, "material.shininess", 64);
		}
		else
		{
			renderer->SetIntUniform(id, "material.specular", 0);
			renderer->SetFloatUniform(id, "material.shininess", 0.0f);
		}
	}

	int BaseGame::AssingEntityID(Entities::Entity* entity)
	{
		int id = nextID++;
		entityList[id] = entity;
		return id;
	}

	Entities::Entity* BaseGame::EntityExists(int id)
	{
		auto it = entityList.find(id);
		
		if (it == entityList.end()) 
			return nullptr;

		return it->second;
	}

	float BaseGame::PixelsToEngine(int objectWidthInPixels, float windowDimension)
	{
		return (objectWidthInPixels * 1.0f) / windowDimension;
	}

	void BaseGame::RunEngine()
	{
		InternalInit();

		while (isRunning && !glfwWindowShouldClose(window->GetWindow()))
		{
			InternalInput();
			InternalUpdate();
			InternalDraw();
		}

		InternalDeinit();
	}
	bool BaseGame::GetKeyDown(Utils::KeyCode key)
	{
		return Input::GetKeyDown(key);
	}
	bool BaseGame::GetKeyUp(Utils::KeyCode key)
	{
		Debugger::ConsoleMessage("Levantaste", static_cast<float>(key));
		return Input::GetKeyUp(key);
	}
	bool BaseGame::GetKeyPressed(Utils::KeyCode key)
	{
		return Input::GetKeyPressed(key);
	}
}