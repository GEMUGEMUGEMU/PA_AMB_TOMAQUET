/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Animation.cpp
*  Purpose:
*  Creation Date: 28-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "PAT_Animation.hpp"


void PAT_Animation::Init(SDL_Renderer* render)
{
	LoadImage(render);
	LoadClips();
}

void PAT_Animation::Draw(int x, int y, SDL_Renderer* renderer)
{
	SDL_Rect* tClip = mClipList.Get(mSpriteIndex);

	SDL_Rect* tDrawPosition = new SDL_Rect();
	tDrawPosition->x = x;
	tDrawPosition->y = y;
	tDrawPosition->w = tClip->w/* * MAGNIFY VALUE*/;
	tDrawPosition->h = tClip->h/* * MAGNIFY VALUE*/;

	SDL_RenderCopy( renderer, mAnimationSheet, tClip, tDrawPosition);

}

void PAT_Animation::ResetAnimation()
{
	mFrameCounter = 0;
	mSpriteIndex= 0;
}

//Update frame counter and preapre what will drawed
PAT_ANIMATION_STATE PAT_Animation::UpdateFrame()
{
	mSpriteIndex = mFrameCounter / FRAMES_PER_CLIP;

	mFrameCounter++;

	if( mSpriteIndex >= mFramesNumber)
	{//Then restart counters
		ResetAnimation();
		return ANIMATION_FINISHED;
	}
		return IN_ANIMATION;
}

