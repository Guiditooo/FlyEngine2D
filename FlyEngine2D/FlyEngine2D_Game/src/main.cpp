#include "Game/Game.h"

void main() 
{
	FEG::Game* game = new FEG::Game();
	game->RunGame();
	delete game;
}