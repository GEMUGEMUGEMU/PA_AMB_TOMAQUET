/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PAT_Game.cpp
*  Purpose:
*  Creation Date: 06-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "PAT_Game.h"
#include <SDL2/SDL_image.h>
#include "SDL_ttf.h"

bool PAT_Game::InitSDL()
{
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		return false;
	}

	int imgFlags = IMG_INIT_PNG;
	/*
	   IMG_INIT_PNG is 2. If you init with IMG_INIT_PNG and
	   get bacK IMG_INIT_PNG you get 2 & 2 which is 2.
	   2 will evaluate to true
	 */
	if(!(IMG_Init(imgFlags) & imgFlags))
	{
		return false;
	}

	if( TTF_Init() == -1 )
	{
		return false;
	}

	return true;
}

void PAT_Game::Run()
{
	if(mWindow)
	{
		double secondsStart;
		double secondsEnd;
		double secondsDelay;
		double deltaTime = 0;

/*
*		_,-'2_,-'2_,-'2_,-'2_,-'2_
*		_,-'2_,            2_,-'2_
*		_,-'2_, MAIN LOOP  2_,-'2_
*		_,-'2_,            2_,-'2_
*		_,-'2_,-'2_,-'2_,-'2_,-'2_
*/
		while(mRunning && !mSceneManager->IsEmpty())
		{
			secondsStart = SDL_GetTicks();

			ProcessInput();

			if(!mSceneManager->IsEmpty())
			{
				Update(deltaTime);

				Render();
			}

			secondsEnd = SDL_GetTicks();
			deltaTime = secondsEnd - secondsStart;
#ifndef DEBUG_MODE
			secondsDelay = FRAME_PER_SECOND - (deltaTime);
			SDL_Delay(secondsDelay);
#endif
		}
	}

	Close();
}


void PAT_Game::Close()
{
	//Destroy window
	SDL_DestroyWindow( mWindow );

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void PAT_Game::ProcessInput()
{
	SDL_Event event;
	while(SDL_PollEvent(&event) != 0 && !mSceneManager->IsEmpty())
	{
		if( event.type == SDL_QUIT )
		{
			mRunning = false;
			break;
		}
		else
		{
			mSceneManager->Input(&event);
		}
	}
}

void PAT_Game::Update(double deltaTime)
{
	mSceneManager->Update(deltaTime);
}

void PAT_Game::Render()
{
	//TODO investigate if it's ok to RenderClear and Render to SceneManager
	mScreen.RenderClear();
	mSceneManager->Draw(mScreen.GetRenderer());
	mScreen.Render();
}

