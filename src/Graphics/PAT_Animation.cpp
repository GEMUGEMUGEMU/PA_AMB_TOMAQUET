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


void PAT_Animation::Init(SDL_Renderer* pRenderer)
{
	LoadImage(pRenderer);
	LoadClips();
}

void PAT_Animation::Draw(int x, int y, SDL_Renderer* pRenderer)
{
	SDL_Rect* temp_clip = mClipList.Get(mSpriteIndex);

	SDL_Rect* temp_draw_position = new SDL_Rect();
	temp_draw_position->x = x;
	temp_draw_position->y = y;
	temp_draw_position->w = temp_clip->w/* * MAGNIFY VALUE*/;
	temp_draw_position->h = temp_clip->h/* * MAGNIFY VALUE*/;

	SDL_RenderCopy( pRenderer, mAnimationSheet, temp_clip, temp_draw_position);

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

