


#ifndef Manager_H
#define Manager_H

#include <sstream>
#include <fstream>
#include <iostream>

#include "Cell.h"

class Manager
{
protected:
	Cell** m_Cells;
	Cell** cpy;
	int m_width;
	int m_height;

	int m_birth;
	int m_death;
	int m_cycle;

	bool m_slant;

public:
	Manager();
	~Manager();

	void set_Parameters(int width, int height, int birth, int death, int cycle);
	void add_cell(int x, int y);
	void init();

	Cell get_Cell(int x, int y);
	int get_width();
	int get_height();

	void analize();
	int neighbors(int x, int y);
	void copy();



};


#endif