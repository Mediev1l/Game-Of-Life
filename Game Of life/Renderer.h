

#ifndef _Renderer_H
#define _Renderer_H

#include "Game.h"


class Renderer : public Game
{
public:

	Renderer() : Game()
	{

	}
	void Draw() override;

};


#endif
