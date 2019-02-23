


#ifndef _Cell_H
#define _Cell_H

#include "Coords.h"

class Cell 
{
protected:
	bool m_Life;

public:
	Cell();

	void set_Life(bool life);

	bool get_Life();

	Cell& operator = (const Cell& c);
};


#endif