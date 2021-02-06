/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PauseScene.cpp
*  Purpose: implement a demo pause scene
*  Creation Date: 07-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "PauseScene.h"
//#include "PauseController.h"
#include "PauseText.h"

PauseScene::~PauseScene()
{
	delete mController;
}

void PauseScene::Init(SDL_Renderer * render)
{
	//PauseController * controller = new PauseController();
	//mController = controller;

	PauseText* pauseText = new PauseText();
	pauseText->Init(10, 300, render);

	mGraphicObjectsList.Add(pauseText);
}

void PauseScene::Update(float deltaTime)
{

}

void PauseScene::Draw(SDL_Renderer * render)
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

void PauseScene::Input(SDL_Event * event)
{
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
//				mController.Input(event);
//				break;
//		}
//	}
}
