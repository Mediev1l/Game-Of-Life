#include "Game.h"

Game::Game()
{
}

void Game::Start()
{
	init();
	Game::add_cell(4, 3);
	Game::add_cell(4, 4);
	Game::add_cell(4, 5);
	Game::analize();
	Draw();

}
