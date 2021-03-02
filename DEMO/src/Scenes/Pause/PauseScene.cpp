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
#include "Commands.hpp"
#include "PAT_Vector2D.hpp"

PauseScene::~PauseScene()
{
	delete mController;
}

void PauseScene::Init(SDL_Renderer * pRenderer)
{
	PauseText* pause_text = new PauseText(PAT_Vector2D(10, 300), pRenderer);

	mGraphicObjectsList.Add(pause_text);

	Commands* cmd = new Commands(PAT_Vector2D(10, 10), pRenderer);
	mGraphicObjectsList.Add(cmd);
}

void PauseScene::Update(float deltaTime)
{

}

void PauseScene::Draw(SDL_Renderer * pRenderer)
{
	uint32_t max = mGraphicObjectsList.GetSize();
	PAT_GraphicObject* graphic_object;

	uint32_t counter = 0;

	while ( counter < max)
	{
		graphic_object = mGraphicObjectsList.Get(counter);
		graphic_object->Draw(pRenderer);
		counter = counter + 1;
	}
}

void PauseScene::Input(SDL_Event * pEvent)
{
	if( pEvent->type == SDL_KEYDOWN)
	{
		switch (pEvent->key.keysym.sym)
		{
			case SDLK_SPACE:
				mState = POP;
				Notify();// to scene manager
				break;
			case SDLK_q:
				mState = POP;
				Notify();// to scene manager
				break;
			default:
      				mController->Input(pEvent);
				break;
		}
	}
}


PAT_Scene* PauseScene::GetSceneToPush()
{
	return nullptr;
}
