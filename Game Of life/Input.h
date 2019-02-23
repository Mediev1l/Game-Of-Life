
#ifndef _Input_H
#define _Input_H

#include <conio.h>


struct Input
{
	enum key { LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3};
	
	key get_Input();
	

};

#endif