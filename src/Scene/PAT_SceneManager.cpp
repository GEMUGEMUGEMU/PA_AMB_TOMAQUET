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
		mpActualScene = mStackScene.GetOnTop();
	}
	else
	{
		mpActualScene = nullptr;
	}
}

void PAT_SceneManager::PushScene(PAT_Scene * pNewScene)
{
	mStackScene.Push(pNewScene);
	mpActualScene = pNewScene;
}

void PAT_SceneManager::InitAndPushScene(PAT_Scene * pNewScene)
{
	pNewScene->Attach(this);
	pNewScene->Init(mpRenderer);
	PushScene(pNewScene);
}

void PAT_SceneManager::Update(double deltaTime)
{
	mpActualScene->Update(deltaTime);
}

void PAT_SceneManager::Draw(SDL_Renderer * pRender)
{
	mpActualScene->Draw(pRender);
}

void PAT_SceneManager::PopOrPushScene()
{
	switch(mpActualScene->mState)
	{
		case POP:
			PopScene();
			break;
		case PUSH_NEW_SCENE:
			InitAndPushScene(mpActualScene->GetSceneToPush());
			break;
		case CONTINUE:
		default:
		break;
	}

}

