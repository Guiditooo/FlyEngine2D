#pragma once

#include "BaseGame/BaseGame.h"
#include "Rectangle/Rectangle.h"
#include "Triangle/Triangle.h"

namespace FEG
{
	class Game : public FlyEngine::BaseGame
	{
	public:
		Game();
		~Game();

		void RunGame();

	private:
		FlyEngine::Entities::Rectangle* rectangle;
		FlyEngine::Entities::Triangle* triangle;

		void Init() override;
		void Update() override;
		void Deinit() override;

	};
}