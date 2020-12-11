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

DemoSceneManager::~DemoSceneManager()
{
	delete mActualScene;
	mActualScene = nullptr;
	SDL_DestroyRenderer(mRender);
}

void DemoSceneManager::Init(SDL_Renderer* renderer)
{
	mRender = renderer;
	DemoScene* demoScene = new DemoScene();
	demoScene->Init(mRender);
	PushScene(demoScene);
}
