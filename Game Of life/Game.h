

#ifndef _Game_H
#define _Game_H

#include "Manager.h"
#include "Input.h"

class Game : public Manager, public Input
{
public:
	Game();

	void Start();
	virtual void Draw() = 0;

};


#endif
