/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: DemoSceneController.cpp
*  Purpose:
*  Creation Date: 02-11-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "SDL2/SDL.h"
#include "DemoSceneController.h"
#include "Vector2D.h"

COMMAND_TYPE DemoSceneController::ManageInput()
{
	SDL_Event event;
	while( SDL_PollEvent( &event ) != 0 )
	{
		//User requests quit
		if( event.type == SDL_QUIT )
		{
			return QUIT;
		}
	}
	if( event.type == SDL_KEYDOWN)
	{
		Vector2D movement;

		switch (event.key.keysym.sym)
		{
			case SDLK_UP:
				{
					Vector2D up(0, -1);
					movement = movement + up;
				}
				break;

			case SDLK_DOWN:
				{
					Vector2D down(0, 1);
					movement = movement + down;
				}
				break;

			case SDLK_LEFT:
				{
					Vector2D left(-1, 0);
					movement = movement + left;
				}
				break;

			case SDLK_RIGHT:
				{
					Vector2D right(1, 0);
					movement = movement + right;
				}
				break;

			default:

				break;
		}
		movement.Normalize();
		mPlayer->SetDirection(movement);

	}


	return NOTHING;
}

DemoSceneController::~DemoSceneController()
{
	delete mPlayer;
}

