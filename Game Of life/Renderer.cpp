#include "Renderer.h"

void Renderer::Draw()
{
	for (int i = 0; i < Game::m_width; i++)
	{
		for (int j = 0; j < Game::m_height; j++)
		{
			if (i == 0 || i == Game::m_width - 1 || j == 0 || j == Game::m_height - 1)
				std::cout << "#";
			else if (Game::m_Cells[i][j].get_Life() == true)
				std::cout << "o";
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}
