/*
File Name: Controller.h
Purpose:
Creation Date: 16-09-20
Created By: Andrea Andreu Salvagnin
*/

#ifndef Controller_h
#define Controller_h

#include "SDL2/SDL.h"

class Controller
{
public:
	Controller(){}
	virtual ~Controller(){ }
	virtual void ManageInput(SDL_Event * event) = 0;
};
#endif /* Controller_h */
