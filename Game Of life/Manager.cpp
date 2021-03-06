#include "Manager.h"

Manager::Manager()
	:m_Cells(nullptr),cpy(nullptr), m_width(0), m_height(0), m_birth(0), m_death(0), m_slant(false)
{

	//m_Cells = new Cell*[m_width];
	//cpy = new Cell*[m_width];
	//
	// for (int i = 0; i < m_width; i++)
	//	 m_Cells[i] = new Cell[m_height];
	//
	//
	//
	//for (int i = 0; i < m_width; i++)
	//	 cpy[i] = new Cell[m_height];
}

Manager::~Manager()
{
	clear();

	for (int i = 0; i < m_width; i++)
		delete[] m_Cells[i];
	delete[] m_Cells;
	   
}

void Manager::set_Parameters(int width, int height, int birth, int death, bool slant)
{
	m_width = width;
	m_height = height;
	m_birth = birth;
	m_death = death;
	m_slant = slant;

	m_Cells = new Cell*[m_width];

	for (int i = 0; i < m_width; i++)
		m_Cells[i] = new Cell[m_height];


}

void Manager::add_cell(int x, int y)
{
	
	if(x > 0 && x < m_width && y > 0 && y < m_height)
		m_Cells[x][y].set_Life(true);

}

void Manager::init()
{
	enum setter { Default = -1, Width = 0, Height = 1, Birth = 2, Death = 3, Slant = 4 };
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
			else if (line.find("Slant") != std::string::npos)
				mode = Slant;
		}
		else if (line != "")
			stream[(int)mode] << line;
	}


	
	set_Parameters( stoi( stream[0].str() ), stoi( stream[1].str() ), stoi(stream[2].str()), stoi(stream[3].str()), to_Bool(stream[4].str()));

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
	for (int i = 1; i < m_width - 1; i++)
	{

		for (int j = 1; j < m_height - 1; j++)
		{
			if (neighbors(i, j) >= m_birth && neighbors(i, j) < m_death)
				m_Cells[i][j].set_Life(true);
			else 
				m_Cells[i][j].set_Life(false);

		}

	}
}

void Manager::clear()
{
	if (m_width != 0 && m_height != 0)
	{
		for (int i = 0; i < m_width; i++)
			delete[] cpy[i];
		delete[] cpy;
	}

}

int Manager::neighbors(int x, int y)
{
	int counter = 0;

	if (m_slant == true)
	{
		if (cpy[x - 1][y - 1].get_Life() == true)
			counter++;
		if (cpy[x - 1][y + 1].get_Life() == true)
			counter++;
		if (cpy[x + 1][y + 1].get_Life() == true)
			counter++;
		if (cpy[x + 1][y - 1].get_Life() == true)
			counter++;
	}
	if (cpy[x - 1][y].get_Life() == true)
		counter++;
	if (cpy[x]    [y + 1].get_Life() == true)
		counter++;
	if (cpy[x]    [y - 1].get_Life() == true)
		counter++;
	if (cpy[x + 1][y].get_Life() == true)
		counter++;
	if (cpy[x][y].get_Life() == true)
		counter++;

	return counter;

}		

void Manager::copy()
{
	if (cpy != nullptr)
		clear();

	cpy = new Cell*[m_width];

	for (int i = 0; i < m_width; i++)
	{
		cpy[i] = new Cell[m_height];
		memcpy(cpy[i], m_Cells[i], m_height * sizeof(Cell));
	}


}

bool Manager::to_Bool(std::string str)
{
	if (str == "true" || str == "TRUE" || str == "True")
		return true;
	else
		return false;

}
