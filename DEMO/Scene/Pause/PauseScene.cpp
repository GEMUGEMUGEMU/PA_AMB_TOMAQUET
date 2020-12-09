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
#include "PauseController.h"

PauseScene::~PauseScene()
{
	delete mController;
}

void PauseScene::Init(SDL_Renderer * render)
{
	PauseController * controller = new PauseController();
	mController = controller;
}

void PauseScene::Update(float deltaTime)
{

}

void PauseScene::Draw(SDL_Renderer * render)
{

}


