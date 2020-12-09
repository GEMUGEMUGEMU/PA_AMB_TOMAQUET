/*
File Name: Controller.h
Purpose:
Creation Date: 16-09-20
Created By: Andrea Andreu Salvagnin
*/

#ifndef Controller_h
#define Controller_h

#include "SDL2/SDL.h"

class Scene;

class Controller
{
public:
	Controller(){ }
	virtual ~Controller(){ }
/*
	envent: event to manage
	nextScene: if event implies a new scene, it will initialize this ponter
 */
	virtual void ManageInput(SDL_Event * event, Scene *& nextScene,
		bool * haveToPop) = 0;
};
#endif /* Controller_h */
