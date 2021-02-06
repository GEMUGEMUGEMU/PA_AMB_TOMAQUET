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
#include "PAT_Vector2D.h"
#include "PauseScene.h"

void DemoSceneController::ManageInput(SDL_Event * event, PAT_Scene *& nextScene,
	bool * haveToPop)
{
	PAT_Scene * tempScene = nullptr;

	if( event->type == SDL_KEYDOWN)
	{
		PAT_Vector2D movement;
		switch (event->key.keysym.sym)
		{
			case SDLK_UP:
				{
					PAT_Vector2D up(0, -1);
					movement = movement + up;
				}
				break;

			case SDLK_DOWN:
				{
					PAT_Vector2D down(0, 1);
					movement = movement + down;
				}
				break;

			case SDLK_LEFT:
				{
					PAT_Vector2D left(-1, 0);
					movement = movement + left;
				}
				break;

			case SDLK_RIGHT:
				{
					PAT_Vector2D right(1, 0);
					movement = movement + right;
				}
				break;
			case SDLK_SPACE:
				tempScene = new PauseScene();
				break;

			case SDLK_q:
				*haveToPop = true;
				break;

			default:

				break;
		}
		movement.Normalize();

		if(!movement.EqualsVectorZero())
		{
			mPlayer->SetDirection(movement);
		}
	}

	nextScene = tempScene;
}

DemoSceneController::~DemoSceneController()
{
	delete mPlayer;
}