/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: DemoScene.cpp
*  Purpose:
*  Creation Date: 01-11-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "DemoScene.hpp"
#include "PAT_Vector2D.hpp"
#include "PAT_Controller.hpp"
//#include "DemoSceneController.hpp"
#include "Player.hpp"
#include "DemoTitle.hpp"
#include "PauseScene.hpp"

DemoScene::~DemoScene()
{
	delete mController;
}

void DemoScene::Init(SDL_Renderer* render)
{
	Player * player = new Player();
	player->Init(32, PAT_Vector2D(200, 100), render);
	mGraphicObjectsList.Add(player);
	mUpdateObjectsList.Add(player);
	mController= player;

//	DemoSceneController* sceneController = new DemoSceneController();
//	sceneController->SetPlayer(player);
//	mController = sceneController;

	DemoTitle* demoText = new DemoTitle();
	demoText->Init(10,10, render);

	mGraphicObjectsList.Add(demoText);
}

void DemoScene::Update(float deltaTime)
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

void DemoScene::Draw(SDL_Renderer * render)
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


void DemoScene::Input(SDL_Event * event)
{
//	if( event->type == SDL_KEYDOWN)
//	{
//		PAT_Vector2D movement;
//		switch (event->key.keysym.sym)
//		{
//			case SDLK_SPACE:
//			{
//				PauseScene* pauseScene = new PauseScene();
//				InitAndPushScene(pauseScene);
//			}
//				break;
//
//			case SDLK_q:
//				PopScene();
//				break;
//			default:
				mController->Input(event);
//				break;
//		}
//	}
}
