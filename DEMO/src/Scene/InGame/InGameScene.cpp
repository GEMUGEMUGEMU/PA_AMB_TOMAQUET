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
	Player * player = new Player();
	player->Init(32, PAT_Vector2D(10, 100), render);

	mGraphicObjectsList.Add(player);
	mUpdateObjectsList.Add(player);
	mCollisionsManager.Add(player);//mHittableObjectsList.Add(player);
	mController = player;

	NPC* npc = new NPC();
	npc->Init(PAT_Vector2D(15, 100), render);
	mGraphicObjectsList.Add(npc);
	mUpdateObjectsList.Add(npc);
	mCollisionsManager.Add(npc);//mHittableObjectsList.Add(npc);

	InGameTitle* title = new InGameTitle();
	title->Init(10,10, render);

	mGraphicObjectsList.Add(title);


	Instructions* instr = new Instructions();
	instr->Init(10,350, render);

	mGraphicObjectsList.Add(instr);
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

//	CheckHitboxesCollisions();
	mCollisionsManager.CheckCollisions();
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
				mState = PUSH_NEW_SCENE;
				Notify();// to scene manager
				break;

			case SDLK_q:
				mState = POP;
				Notify();// to scene manager
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


//void InGameScene::CheckHitboxesCollisions()
//{
//	uint32_t max = mHittableObjectsList.GetSize();
//
//	if(max >= 0)
//	{
//		uint32_t counter = 0;
//		uint32_t iterationCounter = 0;
//
//		PAT_HittableObject* hittEDobj = nullptr;
//		PAT_HittableObject* hittERobj = nullptr;
//		while ( counter < max)
//		{
//			hittEDobj = mHittableObjectsList.Get(counter);
//
//			while (iterationCounter < max)
//			{
//				if(iterationCounter != counter)
//				{
//					hittERobj =
//						mHittableObjectsList.Get(
//							iterationCounter);
//					hittEDobj->HasCollided(hittERobj->GetHitbox());
//				}
//
//				iterationCounter = iterationCounter + 1;
//			}
//
//			counter = counter + 1;
//		}
//
//		counter = 0;
//		while ( counter < max)
//		{
//			hittEDobj = mHittableObjectsList.Get(counter);
//			if(hittEDobj->mHasCollided)
//			{
//				mHittableObjectsList.Remove(hittEDobj);
//				max = mHittableObjectsList.GetSize();
//			}
//
//			counter = counter + 1;
//		}
//	}
//
//
//	//	PAT_LinkedList<PAT_Hitbox> hitboxList;
//	//
//	//	while ( counter < max)
//	//	{
//	//		tObject = mHittableObjectsList.Get(counter);
//	//		hitboxList.Add(tObject->GetHitbox());
//	//		counter = counter + 1;
//	//	}
//	//
//	//	max = hitboxList.GetSize();
//	//	counter = 0;
//}
