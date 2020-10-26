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
	uint32_t tClipNumber = mFrameNumber / FRAMES_PER_CLIP;

	mFrameNumber++;

	if( tClipNumber >= FRAMES_NUMBER)
	{
		mFrameNumber = 0;
		tClipNumber = 0;
	}

	mPreviousClip = tClipNumber;
	SDL_Rect* clip = mClipList.Get(tClipNumber);



	SDL_Rect* drawPosition = new SDL_Rect();
	drawPosition->x = x;
	drawPosition->y = y;
	drawPosition->w = clip->w;
	drawPosition->h = clip->h;

	SDL_RenderCopy( renderer, mAnimationSheet, clip, drawPosition);

}
