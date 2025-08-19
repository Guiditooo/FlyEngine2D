#include "Game.h"

#include <iostream>

#include "Color/Color.h"

using namespace FlyEngine;

namespace FEG
{
	Game::Game() : BaseGame()
	{
		rectangle = nullptr;
		triangle = nullptr;
	}

	Game::~Game()
	{

	}

	void Game::RunGame()
	{
		BaseGame::RunEngine();
	}

	void Game::Init()
	{
		rectangle = CreateRectangle(0, 0, 0, 100);
		triangle = CreateTriangle(0, 0, 0, 100, 100);

		rectangle->SetColor(Utils::COLOR::MAGENTA);
	}

	void Game::Update()
	{
		if (GetKeyUp(Utils::KeyCode::KEY_A))
		{
			triangle->GetTransform()->WorldRotate(0, 30, 0);
		}
	}

	void Game::Deinit()
	{

	}
}