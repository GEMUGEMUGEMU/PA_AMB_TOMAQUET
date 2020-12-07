/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PTA_Game.cpp
*  Purpose:
*  Creation Date: 06-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "PTA_Game.h"

void PTA_Game::Run()
{
	if(mWindow)
	{
		double secondsStart;
		double secondsEnd;
		double secondsDelay;
		double deltaTime = 0;
		while(mRunning)
		{
			secondsStart = SDL_GetTicks();

			////////////////
			//Process input:
			////////////////
			Input();

			/////////
			//Update:
			/////////
			Update(deltaTime);

			/////////
			//Render:
			/////////
			Render();

			secondsEnd = SDL_GetTicks();
			deltaTime = secondsEnd - secondsStart;
			secondsDelay = FRAME_PER_SECOND - (deltaTime);
			SDL_Delay(secondsDelay);
		}
	}

	Close();
}

void PTA_Game::Close()
{
	//Destroy window
	SDL_DestroyWindow( mWindow );

	//Quit SDL subsystems
	SDL_Quit();
}

void PTA_Game::Input()
{
	SDL_Event event;
	while(SDL_PollEvent(&event) != 0)
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

void PTA_Game::Update(double deltaTime)
{
	mSceneManager->Update(deltaTime);
}

void PTA_Game::Render()
{
	mScreen.RenderClear();
	mSceneManager->Draw(mScreen.GetRenderer());
	mScreen.Render();
}

