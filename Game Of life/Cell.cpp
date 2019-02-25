#include "Cell.h"

Cell::Cell()
	: m_Life(false), m_lifeTime(0)
{	
}

void Cell::set_Life(bool life)
{
	m_Life = life;
}

void Cell::increment_LifeTime()
{
	m_lifeTime++;
}

void Cell::reset_LifeTime()
{
	m_lifeTime = 0;
}

bool Cell::get_Life()
{
	return m_Life;
}

int Cell::get_LifeTime()
{
	return m_lifeTime;
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
		m_lifeTime = c.m_lifeTime;
	}

	return *this;
}
