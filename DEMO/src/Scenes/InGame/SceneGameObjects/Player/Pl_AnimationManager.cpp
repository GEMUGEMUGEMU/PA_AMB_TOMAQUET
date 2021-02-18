/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: Pl_AnimationManager.cpp
*  Purpose:
*  Creation Date: 28-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "Pl_AnimationManager.hpp"

Pl_AnimationManager::Pl_AnimationManager() : PAT_AnimationManager() { }

Pl_AnimationManager::~Pl_AnimationManager() { }

void Pl_AnimationManager::Init(SDL_Renderer* renderer)
{
	mRenderer = renderer;

	mAIdle.Init(mRenderer);
	mAMove.Init(mRenderer);
	mAPunch.Init(mRenderer);
}


void Pl_AnimationManager::Draw(int x, int y, PAT_Animation& animation)
{
	animation.Draw(x, y, mRenderer);
}

PAT_ANIMATION_STATE Pl_AnimationManager::Update(PAT_Animation& animation)
{
	return animation.UpdateFrame();
}