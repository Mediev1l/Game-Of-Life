#include "Game.h"

Game::Game()
{
}

void Game::Start()
{
	init();
	Game::add_cell(1, 1);
	Game::add_cell(1, 2);
	Game::add_cell(1, 3);
	Draw();
	Game::analize();
	Draw();
	Game::analize();
	Draw();
	Game::analize();
	Draw();
	Game::analize();
	Draw();	Game::analize();
	Draw();	Game::analize();
	Draw();	Game::analize();
	Draw();

}
