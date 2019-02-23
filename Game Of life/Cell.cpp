#include "Cell.h"

Cell::Cell()
	: m_Life(false) 
{	
}

void Cell::set_Life(bool life)
{
	m_Life = life;
}

bool Cell::get_Life()
{
	return m_Life;
}

Cell & Cell::operator=(const Cell & c)
{
	if (this == &c)
	{
		return *this;
	}
	else
	{
		m_Life = c.m_Life;
	}

	return *this;
}
