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

#include "PauseScene.hpp"
#include "PauseText.hpp"

PauseScene::~PauseScene()
{
	delete mController;
}

void PauseScene::Init(SDL_Renderer * render)
{
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
	PAT_GraphicObject* tObject;

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
}
