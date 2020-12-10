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

void PAT_Game::Run()
{
	if(mWindow)
	{
		double secondsStart;
		double secondsEnd;
		double secondsDelay;
		double deltaTime = 0;

/*
		_,-'2_,-'2_,-'2_,-'2_,-'2_
		_,-'2_,            2_,-'2_
		_,-'2_, MAIN LOOP  2_,-'2_
		_,-'2_,            2_,-'2_
		_,-'2_,-'2_,-'2_,-'2_,-'2_
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
			secondsDelay = FRAME_PER_SECOND - (deltaTime);
			SDL_Delay(secondsDelay);
		}
	}

	Close();
}

void PAT_Game::Close()
{
	//Destroy window
	SDL_DestroyWindow( mWindow );

	//Quit SDL subsystems
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

