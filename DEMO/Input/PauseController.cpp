/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PauseController.cpp
*  Purpose:
*  Creation Date: 07-12-20
*  Created By: Andrea Andreu Salvagnin
*/
#include "PauseController.h"

/*
PauseController::PauseController()
{
	return;
}

PauseController::~PauseController()
{
	return;
}
*/
void PauseController::ManageInput(SDL_Event * event, Scene *& nextScene)
{
	if( event->type == SDL_KEYDOWN)
	{
		switch (event->key.keysym.sym)
		{
			case SDLK_SPACE:
			//POP PAUSE
				break;
		}
	}

}
