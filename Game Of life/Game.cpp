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

	Game::add_cell(15, 7);
	Game::add_cell(15, 8);
	Game::add_cell(10, 7);
	Game::add_cell(10, 8);
	Game::add_cell(10, 9);
	Game::add_cell(10, 10);


	while (1)
	{
		system("cls");
		Draw();
		Game::analize();
		Sleep(1000);
	}



}
