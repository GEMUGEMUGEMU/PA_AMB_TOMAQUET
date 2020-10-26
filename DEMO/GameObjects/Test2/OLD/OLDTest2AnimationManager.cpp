/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Test2AnimationManager.cpp
*  Purpose:
*  Creation Date: 21-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "SDL2/SDL_image.h"
#include "Test2AnimationManager.h"

void Test2AnimationManager::LoadImage(SDL_Renderer* render)
{
	const char* filePath= "./Sprites/Prehistoric.png";

	SDL_Surface* tempSurface = IMG_Load(filePath);

	mWith = tempSurface->w;
	mHeight = tempSurface->h;

	mAnimationSheet = SDL_CreateTextureFromSurface(render, tempSurface);

	SDL_FreeSurface(tempSurface);
}

void Test2AnimationManager::LoadClips()
{
	SDL_Rect* clip1 = new SDL_Rect;
	clip1->x = 0;
	clip1->y = 0;
	clip1->w = 64;
	clip1->h = 64;
	mClipList.Add(clip1);

	SDL_Rect* clip2 = new SDL_Rect;
	clip2->x = 64;
	clip2->y = 0;
	clip2->w = 64;
	clip2->h = 64;
	mClipList.Add(clip2);

	FRAMES_NUMBER = mClipList.GetSize();
}
