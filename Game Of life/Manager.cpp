#include "Manager.h"

Manager::Manager()
	:m_Cells(nullptr),cpy(nullptr), m_width(0), m_height(0), m_birth(0), m_death(0), m_cycle(0)
{

	 m_Cells = new Cell*[m_width];
	
	 for (int i = 0; i < m_width; i++)
		 m_Cells[i] = new Cell[m_height];


	 cpy = new Cell*[m_width];

	 for (int i = 0; i < m_width; i++)
		 cpy[i] = new Cell[m_height];
}

Manager::~Manager()
{
	for (int i = 0; i < m_width; i++)
		delete[] m_Cells[i];
	delete[] m_Cells;
}

void Manager::set_Parameters(int width, int height, int birth, int death, int cycle)
{
	m_width = width;
	m_height = height;
	m_birth = birth;
	m_death = death;
	m_cycle = cycle;

	m_Cells = new Cell*[m_width];

	for (int i = 0; i < m_width; i++)
		m_Cells[i] = new Cell[m_height];


}

void Manager::add_cell(int x, int y)
{
	if (m_width > x && m_height > y)
		m_Cells[x][y].set_Life(true);

}

void Manager::init()
{
	enum setter { Default = -1, Width = 0, Height = 1, Birth = 2, Death = 3, Cycle = 4 };
	std::stringstream stream[5];
	std::fstream file;
	std::string line;
	setter mode = Default;


	file.open("Init.init");

	if (!file.good())
		std::cerr << "[ERROR] Couldn't load the \"Init.init\" file" << std::endl;

	
	while (std::getline(file, line))
	{
		if (line.find("#Settings:") != std::string::npos)
		{
			if (line.find("Init_X") != std::string::npos)
				mode = Width;
			else if (line.find("Init_Y") != std::string::npos)
				mode = Height;
			else if (line.find("Birth") != std::string::npos)
				mode = Birth;
			else if (line.find("Death") != std::string::npos)
				mode = Death;
			else if (line.find("Cycle") != std::string::npos)
				mode = Cycle;
		}
		else if (line != "")
			stream[(int)mode] << line;
	}

	set_Parameters( stoi( stream[0].str() ), stoi( stream[1].str() ), stoi(stream[2].str()), stoi(stream[3].str()), stoi(stream[4].str()));

}

Cell Manager::get_Cell(int x, int y)
{
	return m_Cells[x][y];
}

int Manager::get_width()
{
	return m_width;
}

int Manager::get_height()
{
	return m_height;
}

void Manager::analize()
{
	
	copy();
	for (int i = 1; i < m_height - 1; i++)
	{

		for (int j = 1; j < m_width - 1; j++)
		{
			if (neighbors(i, j) >= m_birth && neighbors(i, j) < m_death)
				m_Cells[i][j].set_Life(true);
			else
				m_Cells[i][j].set_Life(false);

		}

	}
}

int Manager::neighbors(int x, int y)
{
	int counter = 0;


	if      (cpy[x - 1][y - 1].get_Life() == true)
		counter++;
	if (cpy[x - 1][y].get_Life() == true)
		counter++;
	if (cpy[x - 1][y + 1].get_Life() == true)
		counter++;
	if (cpy[x]    [y + 1].get_Life() == true)
		counter++;
	if (cpy[x]    [y - 1].get_Life() == true)
		counter++;
	if (cpy[x + 1][y].get_Life() == true)
		counter++;
	if (cpy[x + 1][y + 1].get_Life() == true)
		counter++;
	if (cpy[x + 1][y - 1].get_Life() == true)
		counter++;

	return counter;

}		

void Manager::copy()
{
	
	cpy = new Cell*[m_width];

	for (int i = 0; i < m_width; i++)
	{
		cpy[i] = new Cell[m_height];
		memcpy(cpy[i], m_Cells[i], m_height * sizeof(Cell));
	}


}
