/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: DemoSceneManager.cpp
*  Purpose:
*  Creation Date: 06-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "DemoSceneManager.h"
#include "DemoScene.h"
#include "PauseScene.h"

DemoSceneManager::~DemoSceneManager()
{//TODO: move this to PAT_SceneManager
//	delete mActualScene;
//	mActualScene = nullptr;
//	SDL_DestroyRenderer(mRender);
}

void DemoSceneManager::Init(SDL_Renderer* renderer)
{
	mRender = renderer;
	DemoScene* demoScene = new DemoScene();
//	demoScene->Init(mRender);
//	PushScene(demoScene);
	InitAndPushScene( demoScene);
	//InitAndPushScene(new DemoScene());
}

void DemoSceneManager::Input(SDL_Event * event)
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
