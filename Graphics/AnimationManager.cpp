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

AnimationManager::AnimationManager() : mAnimationSheet(nullptr){}

void AnimationManager::Init(SDL_Renderer* render)
{
	LoadImage(render);
	LoadClips();
}

void AnimationManager::Draw(int x, int y, SDL_Renderer* renderer)
{
	uint32_t clipIndex = mFrameNumber / FRAMES_PER_CLIP;

	mFrameNumber++;

	if(mFrameNumber / FRAMES_PER_CLIP  >= FRAMES_NUMBER)
	{
		mFrameNumber = 0;
	}

	if (mPreviousClip != clipIndex || (clipIndex == 0 && mFrameNumber == 0))
	{
		mPreviousClip = clipIndex;
		SDL_Rect* clip = mClipList.Get(clipIndex);



		SDL_Rect* drawPosition = new SDL_Rect();
		drawPosition->x = x;
		drawPosition->y = y;
		drawPosition->w = clip->w;
		drawPosition->h = clip->h;

		SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
		SDL_RenderClear( renderer ); 
		SDL_RenderCopy( renderer, mAnimationSheet, clip, drawPosition);	

	}
}
