/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: AnimationManager.cpp
*  Purpose:
*  Creation Date: 03-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "AnimationManager.h"
#include "SDL2/SDL_image.h"

AnimationManager::AnimationManager() {}

void AnimationManager::Update()
{
	mActualAnimation->UpdateFrame();
}

void AnimationManager::Draw(int x, int y, SDL_Renderer* renderer)
{
	mActualAnimation->Draw(x, y, renderer);
}

void AnimationManager::SetAnimation(PAT_Animation* newAnimation)
{
	delete(mActualAnimation);
	newAnimation->Init(mRender);
	mActualAnimation = newAnimation;
}

