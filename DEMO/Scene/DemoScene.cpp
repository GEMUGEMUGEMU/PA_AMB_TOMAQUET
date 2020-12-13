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
#include "Test1.h"
#include "Test2.h"
#include "Player.h"
#include "Instructions.h"
#include "Instructions2.h"
#include "Screen.h"
#include "Controller.h"

DemoScene::~DemoScene()
{
	delete mController;
}
void DemoScene::Init(SDL_Renderer* render)
{
	AnimatedStaticObject* animatedStatic = new Test1();
	animatedStatic->Init(100, 100, render);
	mGraphicObjectsList.Add(animatedStatic);
	mUpdateObjectsList.Add(animatedStatic);


	AnimatedKineticObject* animatedKinetic = new Test2();
	animatedKinetic->Init(5, 300, 100, render);
	mGraphicObjectsList.Add(animatedKinetic);
	mUpdateObjectsList.Add(animatedKinetic);

	Player * player = new Player();
	player->Init(5, 200, 100, render);
	mGraphicObjectsList.Add(player);
	mUpdateObjectsList.Add(player);



	Instructions* instructions = new Instructions();
	instructions->Init(400, 400, render);
	mGraphicObjectsList.Add(instructions);

	Instructions2* instructions2 = new Instructions2();
	instructions2->Init(50, 400, render);
	mGraphicObjectsList.Add(instructions2);



	DemoSceneController* sceneController = new DemoSceneController();
	sceneController->SetPlayer(player);

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

