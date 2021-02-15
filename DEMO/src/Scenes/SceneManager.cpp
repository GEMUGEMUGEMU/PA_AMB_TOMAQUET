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
//	inGameScene->Attach(this);
	InitAndPushScene( inGameScene );
}

void SceneManager::Input(SDL_Event * event)
{
	mActualScene->Input(event);
}


void SceneManager::UpdateFromSubject(PAT_Subject* changedSubject)
{
	if(changedSubject == mActualScene)
	{
		PopOrPushScene();
	}
}

