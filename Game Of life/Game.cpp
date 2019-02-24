#include "Game.h"

Game::Game()
{
}

void Game::Start()
{
	init();
	Game::add_cell(2, 1);
	Game::add_cell(2, 2);
	Game::add_cell(2, 3);
	Draw();
	Game::analize();
	Draw();
	Game::analize();
	Draw();
	Game::analize();
	Draw();
	Game::analize();


}
