

#ifndef _Coords_H
#define _Coords_H

class Coords
{
protected:
	int m_X;
	int m_Y;
public:

	Coords();

	void set_X(int x);
	void set_Y(int y);

	int get_X();
	int get_Y();

	
};

#endif