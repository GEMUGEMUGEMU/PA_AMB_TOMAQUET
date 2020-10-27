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
	SDL_Rect* tClip = mClipList.Get(mSpriteIndex);
	SDL_RenderCopy( renderer, mAnimationSheet, tClip, tDrawPosition);

	SDL_Rect* tDrawPosition = new SDL_Rect();
	tDrawPosition->x = x;
	tDrawPosition->y = y;
	tDrawPosition->w = tClip->w;
	tDrawPosition->h = tClip->h;

	SDL_RenderCopy( renderer, mAnimationSheet, tClip, tDrawPosition);

}

void AnimationManager::UpdateFrame()
{
	mSpriteIndex = mFrameNumber / FRAMES_PER_CLIP;

	mFrameNumber++;

	if( mSpriteIndex >= FRAMES_NUMBER )
	{
		mFrameNumber = 0;
		mSpriteIndex= 0;
	}
}
