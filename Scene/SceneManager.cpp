/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: SceneManager.cpp
*  Purpose:
*  Creation Date: 04-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "SceneManager.h"

void SceneManager::PopScene()
{
	mStackScene.Pop();
	if(!mStackScene.IsEmpty())
	{
		mActualScene = mStackScene.GetOnTop();
	}
}

void SceneManager::PushScene(Scene * newScene)
{
	mStackScene.Push(newScene);
	mActualScene = newScene;
	mController = newScene->GetController();
}

void SceneManager::Input(SDL_Event * event)
{
	Scene * sceneToPush = nullptr;
	mController->ManageInput(event, sceneToPush);
	if(sceneToPush != nullptr)
	{
		PushScene(sceneToPush);
	}
}

void SceneManager::Update(double deltaTime)
{
	mActualScene->Update(deltaTime);
}

void SceneManager::Draw(SDL_Renderer * render)
{
	mActualScene->Draw(render);
}
