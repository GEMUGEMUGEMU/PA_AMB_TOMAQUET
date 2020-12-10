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

bool SceneManager::IsEmpty()
{
	return mStackScene.IsEmpty();
}

void SceneManager::PopScene()
{
	mStackScene.Pop();
	if(!mStackScene.IsEmpty())
	{
		mActualScene = mStackScene.GetOnTop();
		mController = mActualScene->GetController();
	}
	else
	{
		mActualScene = nullptr;
		//Controller is deleted by popped scene in mStackScene
		mController = nullptr;

	}
}

void SceneManager::PushScene(PTA_Scene * newScene)
{
	mStackScene.Push(newScene);
	mActualScene = newScene;
	mController = newScene->GetController();
}

void SceneManager::InitAndPushScene(PTA_Scene * newScene)
{
	newScene->Init(mRender);
	PushScene(newScene);
}


void SceneManager::Input(SDL_Event * event)
{
	/*
	   sceneToPush isn't initialized to nullptr because it have to be
	   dereferenciable in mController->ManageInput
	 */
	PTA_Scene * sceneToPush;
	bool haveToPop = false;
	mController->ManageInput(event, sceneToPush, &haveToPop);

	if(sceneToPush != nullptr)
	{
		InitAndPushScene(sceneToPush);
	}
	if(haveToPop)
	{
		PopScene();
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
