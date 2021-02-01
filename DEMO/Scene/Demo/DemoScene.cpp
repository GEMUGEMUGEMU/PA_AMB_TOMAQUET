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

#include "DemoScene.h"
#include "DemoSceneController.h"
#include "Player.h"
#include "Screen.h"
#include "Controller.h"
#include "DemoTitle.h"

DemoScene::~DemoScene()
{
	delete mController;
}
void DemoScene::Init(SDL_Renderer* render)
{
	Player * player = new Player();
	player->Init(32, 200, 100, render);
	mGraphicObjectsList.Add(player);
	mUpdateObjectsList.Add(player);

	DemoSceneController* sceneController = new DemoSceneController();
	sceneController->SetPlayer(player);

	DemoTitle* demoText = new DemoTitle();
	demoText->Init(10,10, render);

	mGraphicObjectsList.Add(demoText);


	mController = sceneController;

}

void DemoScene::Update(float deltaTime)
{

	uint32_t max = mUpdateObjectsList.GetSize();
	UpdateObject* tObject;

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
	GraphicObject* tObject;

	uint32_t counter = 0;

	while ( counter < max)
	{
		tObject = mGraphicObjectsList.Get(counter);
		tObject->Draw(render);
		counter = counter + 1;
	}
}

