/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PAT_SceneManager.cpp
*  Purpose:
*  Creation Date: 04-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "PAT_SceneManager.hpp"

bool PAT_SceneManager::IsEmpty()
{
	return mStackScene.IsEmpty();
}

void PAT_SceneManager::PopScene()
{
	mStackScene.Pop();
	if(!mStackScene.IsEmpty())
	{
		mActualScene = mStackScene.GetOnTop();
	}
	else
	{
		mActualScene = nullptr;
	}
}

void PAT_SceneManager::PushScene(PAT_Scene * newScene)
{
	mStackScene.Push(newScene);
	mActualScene = newScene;
}

void PAT_SceneManager::InitAndPushScene(PAT_Scene * newScene)
{
	newScene->Attach(this);
	newScene->Init(mRender);
	PushScene(newScene);
}

void PAT_SceneManager::PopAndPushScene(PAT_Scene * newScene)
{
	PopScene();
	newScene->Init(mRender);
	PushScene(newScene);
}

void PAT_SceneManager::Update(double deltaTime)
{
	mActualScene->Update(deltaTime);
}

void PAT_SceneManager::Draw(SDL_Renderer * render)
{
	mActualScene->Draw(render);
}

void PAT_SceneManager::PopOrPushScene()
{
	switch(mActualScene->mState)
	{
		case POP:
			PopScene();
			break;
		case PUSH_NEW_SCENE:
			InitAndPushScene(mActualScene->GetSceneToPush());
			break;
		case CONTINUE:
		default:
		break;
	}

}

