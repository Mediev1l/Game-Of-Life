#include <iostream>
#include <conio.h>
#include "Game.h"
#include "Renderer.h"



int main()
{

	Game* Life = new Renderer();
	Life->Start();


	std::cin.get();
	return 0;
	
}