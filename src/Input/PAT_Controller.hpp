/*
File Name: PAT_Controller.hpp
Purpose: Manages input
Creation Date: 16-09-20
Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Controller_hpp
#define PAT_Controller_hpp

#include "SDL2/SDL.h"

class PAT_Controller
{
public:
	PAT_Controller(){ }
	virtual ~PAT_Controller(){ }
	virtual void Input(SDL_Event * event) = 0;
/*
	envent: event to manage
	nextScene: if event implies a new scene, it will initialize this ponter
*/
//	virtual void ManageInput(SDL_Event * event, PAT_Scene *& nextScene,
//		bool * haveToPop) = 0;
};
#endif /* PAT_Controller_hpp */
