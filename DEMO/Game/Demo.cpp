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

#include "Demo.h"
#include "DemoSceneManager.h"
#include <SDL2/SDL_image.h>

double PTA_Game::FRAME_PER_SECOND = 30;

bool Demo::Init(uint32_t width, uint32_t height, const char* windowName)
{
	//InitWindow() ??
	mWindow = mScreen.Init(width, height, windowName);
	if(mWindow == nullptr)
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

	SDL_SetRenderDrawColor( mScreen.GetRenderer(), 0, 0, 255, 255 );

//	INITIALIZE SCENE MANAGER
	mSceneManager = new DemoSceneManager();
	mSceneManager->Init(mScreen.GetRenderer());
	mRunning = true;

	return true;
}

Demo::~Demo()
{
	delete mSceneManager;
}
