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

void PauseController::ManageInput(SDL_Event * event, PTA_Scene *& nextScene,
	bool * haveToPop)
{
	PTA_Scene * tempScene = nullptr;

	if( event->type == SDL_KEYDOWN)
	{
		switch (event->key.keysym.sym)
		{
			case SDLK_SPACE:
				*haveToPop = true;
				break;
		}
	}

	nextScene = tempScene;
}
