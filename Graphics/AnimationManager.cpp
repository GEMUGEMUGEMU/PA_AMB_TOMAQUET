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

AnimationManager::AnimationManager() /*: mAnimationSheet(nullptr)*/{}

void AnimationManager::Update()
{
	mActualAnimation->UpdateFrame();
}

//void AnimationManager::Init(SDL_Renderer* render)
//{
//	LoadImage(render);
//	LoadClips();
//}

void AnimationManager::Draw(int x, int y, SDL_Renderer* renderer)
{
	mActualAnimation->Draw(x, y, renderer);

//	SDL_Rect* tClip = mClipList.Get(mSpriteIndex);
//
//	SDL_Rect* tDrawPosition = new SDL_Rect();
//	tDrawPosition->x = x;
//	tDrawPosition->y = y;
//	tDrawPosition->w = tClip->w;
//	tDrawPosition->h = tClip->h;
//
//	SDL_RenderCopy( renderer, mAnimationSheet, tClip, tDrawPosition);
//
}

void AnimationManager::SetAnimation(PAT_Animation* newAnimation)
{
	delete(mActualAnimation);
	newAnimation->Init(mRender);
	mActualAnimation = newAnimation;
}
//Update frame counter in order to preapre the frame to be drawed
//void AnimationManager::UpdateFrame()
//{
//	mSpriteIndex = mFrameCounter / FRAMES_PER_CLIP;
//
//	mFrameCounter++;
////TODO: put everithing on Animation
////TODO: decouple this
//	if( mSpriteIndex >= FRAMES_NUMBER )
//	{//Then restart counters
//		mFrameCounter = 0;
//		mSpriteIndex= 0;
//	}
//}
