/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: GraphicSystem.cpp
*  Purpose:
*  Creation Date: 24-04-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "GraphicSystem.hpp"
#include "PrehistoricSprite.hpp"
#include "SpritePosition.hpp"

GraphicSystem::GraphicSystem() : mWindow(400, 600, "NISHIKIGOI DEMO")
{
}

GraphicSystem::~GraphicSystem()
{
}

unsigned short int GraphicSystem::Init(ECS::PAT_EntityManager* pEntityManager)
{
	if (mWindow.Init() != 0)
	{
		return 1;
	}

//TODO: return state
	mPrehistoricSpriteSheet.Init(&mWindow.mRenderer);
	ECS::EntityID eid = pEntityManager->CreateEntity();
	pEntityManager->CreateComponent<SpritePosition>(eid);

	return 0;
}


void GraphicSystem::Update(ECS::PAT_EntityManager* pEntityManager)
{
	mWindow.CleanRender();
	ECS::Vector<SpritePosition> sprites_vector =
		pEntityManager->GetComponents<SpritePosition>();

	for (auto it = sprites_vector.Begin(); it != sprites_vector.End();)
	{
		mWindow.AddToRender(&mPrehistoricSpriteSheet, &it->mSpritePos);
		it++;
	}

	mWindow.Render();
}
