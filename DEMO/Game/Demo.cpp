/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Demo.cpp
*  Purpose: Implement Game.h in order to create a demo of pa amb tomàquet
*  Creation Date: 16-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "Game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "LinkedList.h"
#include "DemoScene.h"

double Game::FRAME_PER_SECOND = 30;

Game& Game::Singleton()
{
	static Game theGame;
	return theGame;
}

bool Game::Init(uint32_t width, uint32_t height, const char* windowName)
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

	DemoScene* demoScene = new DemoScene();
	demoScene->Init(mScreen.GetRenderer());
	mStackScene.Push(demoScene);

	actualScene = demoScene;
	mController = demoScene->GetController();

	mRunning = true;

	return true;
}

void Game::Run()
{
	uint32_t value;

	if(mWindow)
	{
		double mSecStart;
		double mSecEnd;
		double mSecDelay;
		double deltaTime = 0;
		while(mRunning)
		{
			mSecStart= SDL_GetTicks();

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

			mSecEnd = SDL_GetTicks();
			deltaTime = mSecEnd - mSecStart;
			mSecDelay = FRAME_PER_SECOND - (deltaTime);
			SDL_Delay(mSecDelay);
		}
	}

	Close();
}

void Game::Close()
{
	//Destroy window
	SDL_DestroyWindow( mWindow );

	//Quit SDL subsystems
	SDL_Quit();
}

void Game::Update(double deltaTime)
{
	actualScene->Update(deltaTime);
}

void Game::Draw()
{
	actualScene->Draw(mScreen.GetRenderer());
}

void Game::Render()
{

	//SDL_RenderClear( mScreen.GetRenderer() );
	mScreen.RenderClear();

	Draw();

	//SDL_RenderPresent(mScreen.GetRenderer());
	mScreen.Render();


}

void Game::Input()
{
	COMMAND_TYPE value = mController->ManageInput();
	switch(value)
	{
		case QUIT:
			mRunning = false;
			break;
		case PAUSE:
//			PauseScene pause = new PauseScene();
			break;
	}
	/*
	if(value == QUIT)
	{
		mRunning = false;
		break;
	}
	*/
}



