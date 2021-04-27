/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Game.cpp
*  Purpose:
*  Creation Date: 06-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "Game.hpp"

Game::Game()
{
}

Game::~Game()
{
}


short unsigned int Game::Init()
{
	mGraphicSystem.Init(&mEntityManager);
	return 0;
}


void Game::Run()
{
	double seconds_start;
#ifndef DEBUG_MODE
	double seconds_delay;
#endif
	double milliseconds_end;
	double delta_time = 0;

/*
*	_,-'2_,-'2_,-'2_,-'2_,-'2_
*	_,-'2_,            2_,-'2_
*	_,-'2_, MAIN LOOP  2_,-'2_
*	_,-'2_,            2_,-'2_
*	_,-'2_,-'2_,-'2_,-'2_,-'2_
*/
	while(mRunning /*&& !mSceneManager->IsEmpty()*/)
	{
		//			seconds_start = SDL_GetTicks();

		ProcessInput();

		//			if(!mSceneManager->IsEmpty())
		//			{
		//				Update(delta_time);

		Render();
		//			}

		milliseconds_end = PAT_System::GetTicks();
		delta_time = milliseconds_end - seconds_start;
#ifndef DEBUG_MODE
		seconds_delay = FRAME_PER_SECOND - (delta_time);
		PAT_System::Delay(seconds_delay);
#endif
	}


	//	Close();
}


void Game::ProcessInput()
{
	SDL_Event event;
	while(SDL_PollEvent(&event) != 0/* && !mSceneManager->IsEmpty()*/)
	{
		if( event.type == SDL_QUIT )
		{
			mRunning = false;
			break;
		}
		//		else
		//		{
		//			mSceneManager->Input(&event);
		//		}
	}
}

//void Game::Update(double deltaTime)
//{
//	mSceneManager->Update(deltaTime);
//}

void Game::Render()
{
	mGraphicSystem.Update(&mEntityManager);
}

