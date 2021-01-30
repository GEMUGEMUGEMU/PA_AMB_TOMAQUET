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

PlayerAnimationManager::PlayerAnimationManager() : AnimationManager() { }

PlayerAnimationManager::~PlayerAnimationManager() { }

void PlayerAnimationManager::Init(SDL_Renderer* render)
{
	mRender = render;
	SetAnimation(new PlayerAIdle);
}
