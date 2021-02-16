/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: InGameScene.cpp
*  Purpose:
*  Creation Date: 01-11-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "InGameScene.hpp"
#include "PAT_Vector2D.hpp"
#include "PAT_Controller.hpp"
#include "PAT_Hitbox.hpp"
#include "Player.hpp"
#include "NPC.hpp"
#include "InGameTitle.hpp"
#include "PauseScene.hpp"
#include "Instructions.hpp"

InGameScene::~InGameScene()
{
	delete mController;
}

void InGameScene::Init(SDL_Renderer* render)
{
	mGameObjsManager.Init(render);
}

void InGameScene::Update(float deltaTime)
{
	mGameObjsManager.Update(deltaTime);

	mGameObjsManager.CheckCollisions();
}

void InGameScene::Draw(SDL_Renderer * renderer)
{
	mGameObjsManager.Draw(renderer);
}


void InGameScene::Input(SDL_Event * event)
{
	if( event->type == SDL_KEYDOWN)
	{
		PAT_Vector2D movement(0, 0);
		switch (event->key.keysym.sym)
		{
			case SDLK_SPACE:
				mState = PUSH_NEW_SCENE;
				Notify();// to scene manager
				break;

			case SDLK_q:
				mState = POP;
				Notify();// to scene manager
				break;
			default:
				mGameObjsManager.Input(event);
				break;
		}
	}
}

PAT_Scene* InGameScene::GetSceneToPush()
{
	return new PauseScene();
}

