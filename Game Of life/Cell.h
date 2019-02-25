


#ifndef _Cell_H
#define _Cell_H

#include "Coords.h"

class Cell 
{
protected:
	bool m_Life;
	int m_lifeTime;

public:
	Cell();

	void set_Life(bool life);
	void increment_LifeTime();
	void reset_LifeTime();

	bool get_Life();

	int get_LifeTime();

	Cell& operator = (const Cell& c);
};


#endif