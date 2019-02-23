#include "Coords.h"

Coords::Coords()
	: m_X(0), m_Y(0)
{
}

void Coords::set_X(int x)
{
	m_X = x;
}

void Coords::set_Y(int y)
{
	m_Y = y;
}

int Coords::get_X()
{
	return m_X;
}

int Coords::get_Y()
{
	return m_Y;
}
