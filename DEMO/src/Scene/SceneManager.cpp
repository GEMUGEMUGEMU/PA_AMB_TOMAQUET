/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: SceneManager.cpp
*  Purpose:
*  Creation Date: 06-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "SceneManager.hpp"
#include "InGameScene.hpp"
#include "PauseScene.hpp"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Init(SDL_Renderer* renderer)
{
	mRender = renderer;
	InGameScene* inGameScene = new InGameScene();
	InitAndPushScene( inGameScene );
}

void SceneManager::Input(SDL_Event * event)
{
	if( event->type == SDL_KEYDOWN)
	{
		switch (event->key.keysym.sym)
		{
			case SDLK_SPACE:
			 {
				PauseScene* pauseScene = new PauseScene();
				InitAndPushScene(pauseScene);
			 }
				break;

			case SDLK_q:
				PopScene();
				break;

			default:
				break;
		}
	}

	mActualScene->Input(event);
}
