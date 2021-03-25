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

GraphicSystem::GraphicSystem() : mWindow(400, 600, "NISHIKIGOI DEMO")
{
}

GraphicSystem::~GraphicSystem()
{
}

unsigned short int GraphicSystem::Init()
{
	mWindow.Init();
	return mSprite.Init(mWindow.mRenderer);
}

void GraphicSystem::Update()
{
	mWindow.AddToRender(&mSprite);
	mWindow.Render();
	mWindow.CleanRender();
}

//void GraphicSystem::Update(ECS::PAT_GameContext* pGameContext)
//{
//	mWindow.Render();
//}
