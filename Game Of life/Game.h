

#ifndef _Game_H
#define _Game_H

#include "Manager.h"
#include "Input.h"
#include <Windows.h>

class Game : public Manager, public Input
{
public:
	Game();

	void Start();
	void Update();
	void Logic();
	void Input();
	virtual void Draw() = 0;

};


#endif
