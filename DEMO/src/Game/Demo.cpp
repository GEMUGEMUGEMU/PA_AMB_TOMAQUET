/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Demo.cpp
*  Purpose:
*  Creation Date: 16-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "Demo.hpp"
#include "SceneManager.hpp"

double PAT_Game::FRAME_PER_SECOND = 30;

bool Demo::Init(uint32_t width, uint32_t height, const char* windowName)
{
	if(!PAT_Game::InitSDL())
	{
		return false;
	}

	//InitWindow() ??
	mWindow = mScreen.Init(width, height, windowName);
	if(mWindow == nullptr)
	{
		return false;
	}

	SDL_SetRenderDrawColor( mScreen.GetRenderer(), 0, 0, 255, 255 );

	//	INITIALIZE SCENE MANAGER
	mSceneManager = new SceneManager();
	mSceneManager->Init(mScreen.GetRenderer());
	mRunning = true;

	return true;
}


Demo::~Demo()
{
	delete mSceneManager;
}
