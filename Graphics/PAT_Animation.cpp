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

#include "PAT_Animation.h"


//PAT_Animation::PAT_Animation() : mAnimationSheet(nullptr){}

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
	tDrawPosition->w = tClip->w;
	tDrawPosition->h = tClip->h;

	SDL_RenderCopy( renderer, mAnimationSheet, tClip, tDrawPosition);

}

void PAT_Animation::ResetAnimation()
{
	mFrameCounter = 0;
	mSpriteIndex= 0;
}

//Update frame counter and preapre what will drawed
void PAT_Animation::UpdateFrame()
{
	mSpriteIndex = mFrameCounter / mFramesNumber;

	mFrameCounter++;

	if( mSpriteIndex >= FRAMES_PER_CLIP )
	{//Then restart counters
		ResetAnimation();
	}
}
