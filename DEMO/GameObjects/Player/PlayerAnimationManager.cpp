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
//	mAIdle.Init(render);
//	mActualAnimation = new PlayerAIdle;
//	mAnimation->Init(render);
//TODO pass initialization to anim manager
//	PlayerAIdle * aIdle = new PlayerAIdle();
//	aIdle->Init(render);
//	SetAnimation(aIdle);

	mRender = render;
	SetAnimation(new PlayerAIdle);
}

//void PlayerAnimationManager::SetAnimation(PAT_Animation* newAnimation)
//{
//	delete(mAnimation);
//	mAnimation = newAnimation;
//}

//void Draw(int x, int y, SDL_Renderer* renderer)
//{
//	mActualAnimation.(x, y, renderer);
//}
