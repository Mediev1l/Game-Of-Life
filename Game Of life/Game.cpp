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

	Game::add_cell(5, 7);
	Game::add_cell(5, 8);
	Game::add_cell(6, 7);
	Game::add_cell(6, 8);

	while (1)
	{
		system("cls");
		Draw();
		Game::analize();
		Sleep(1000);
	}



}
