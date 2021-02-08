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
		//mController = mActualScene->GetController();
	}
	else
	{
		mActualScene = nullptr;
		//Controller is deleted by popped scene in mStackScene
		//mController = nullptr;

	}
}

void PAT_SceneManager::PushScene(PAT_Scene * newScene)
{
	mStackScene.Push(newScene);
	mActualScene = newScene;
	//mController = newScene->GetController();
}

void PAT_SceneManager::InitAndPushScene(PAT_Scene * newScene)
{
	newScene->Init(mRender);
	PushScene(newScene);
}

//TODO:Should be virtual
//void PAT_SceneManager::Input(SDL_Event * event)
//{
//	if( event->type == SDL_KEYDOWN)
//	{
//		PAT_Vector2D movement;
//		switch (event->key.keysym.sym)
//		{
//			case SDLK_SPACE:
//				InitAndPushScene(new PauseScene());
//				break;
//
//			case SDLK_q:
//				PopScene();
//				break;
//			default:
//
//				break;
//		}
//}
//void PAT_SceneManager::Input(SDL_Event * event)
//{
//	/*
//	   sceneToPush isn't initialized to nullptr because it have to be
//	   dereferenciable in mController->ManageInput
//	 */
//	PAT_Scene * sceneToPush;
//	bool haveToPop = false;
//	mController->ManageInput(event, sceneToPush, &haveToPop);
//
//	if(sceneToPush != nullptr)
//	{
//		InitAndPushScene(sceneToPush);
//	}
//	if(haveToPop)
//	{
//		PopScene();
//	}
//}

void PAT_SceneManager::Update(double deltaTime)
{
	mActualScene->Update(deltaTime);
}

void PAT_SceneManager::Draw(SDL_Renderer * render)
{
	mActualScene->Draw(render);
}
