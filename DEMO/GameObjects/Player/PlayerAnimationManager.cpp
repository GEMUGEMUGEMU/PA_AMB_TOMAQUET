/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PlayerAnimationManager.cpp
*  Purpose:
*  Creation Date: 28-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "PlayerAnimationManager.h"

PlayerAnimationManager::PlayerAnimationManager() : PAT_AnimationManager() { }

PlayerAnimationManager::~PlayerAnimationManager() { }

void PlayerAnimationManager::Init(SDL_Renderer* render)
{
	mRender = render;
	//SetAnimation(new PlayerAIdle);

	mAIdle.Init(mRender);
	mAMove.Init(mRender);
	//mAPunch.Init(mRender);
}


void PlayerAnimationManager::Draw(int x, int y, PAT_Animation& animation)
{
	animation.Draw(x, y, mRender);
}

void PlayerAnimationManager::Update(PAT_Animation& animation)
{
	animation.UpdateFrame();
}
