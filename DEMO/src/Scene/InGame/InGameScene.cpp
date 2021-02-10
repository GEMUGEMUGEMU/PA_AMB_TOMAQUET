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
#include "Player.hpp"
#include "InGameTitle.hpp"
#include "PauseScene.hpp"

InGameScene::~InGameScene()
{
	delete mController;
}

void InGameScene::Init(SDL_Renderer* render)
{
	Player * player = new Player();
	player->Init(32, PAT_Vector2D(200, 100), render);
	mGraphicObjectsList.Add(player);
	mUpdateObjectsList.Add(player);
	mController = player;

	InGameTitle* demoText = new InGameTitle();
	demoText->Init(10,10, render);

	mGraphicObjectsList.Add(demoText);
}

void InGameScene::Update(float deltaTime)
{

	uint32_t max = mUpdateObjectsList.GetSize();
	PAT_UpdateObject* tObject;

	uint32_t counter = 0;

	while ( counter < max)
	{
		tObject = mUpdateObjectsList.Get(counter);
		tObject->Update(deltaTime);
		counter = counter + 1;
	}
}

void InGameScene::Draw(SDL_Renderer * render)
{
	uint32_t max = mGraphicObjectsList.GetSize();
	PAT_GraphicObject* tObject;

	uint32_t counter = 0;

	while ( counter < max)
	{
		tObject = mGraphicObjectsList.Get(counter);
		tObject->Draw(render);
		counter = counter + 1;
	}
}


void InGameScene::Input(SDL_Event * event)
{
	if( event->type == SDL_KEYDOWN)
	{
		PAT_Vector2D movement;
		switch (event->key.keysym.sym)
		{
			case SDLK_SPACE:
//			{
//				PauseScene* pauseScene = new PauseScene();
//				InitAndPushScene(pauseScene);
				mState = PUSH_NEW_SCENE;
				Notify();// to scene manager
//			}
				break;

			case SDLK_q:
				mState = POP;
				Notify();// to scene manager
//				PopScene();
				break;
			default:
      				mController->Input(event);
				break;
		}
	}
}

PAT_Scene* InGameScene::GetSceneToPush()
{
	return new PauseScene();
}
