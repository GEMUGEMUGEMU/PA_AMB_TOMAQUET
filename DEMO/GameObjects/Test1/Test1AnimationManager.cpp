/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Test1AnimationManager.cpp
*  Purpose: Animation Manager of Test1.cpp 
*  Creation Date: 16-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "Test1AnimationManager.h"
#include "SDL2/SDL_image.h"

void Test1AnimationManager::LoadImage(SDL_Renderer* render)
{
	const char* filePath= "./Sprites/Triangle.png";

	SDL_Surface* tempSurface = IMG_Load(filePath);

	mWith = tempSurface->w;
	mHeight = tempSurface->h;

	mAnimationSheet = SDL_CreateTextureFromSurface(render, tempSurface);

	SDL_FreeSurface(tempSurface);
}

void Test1AnimationManager::LoadClips()
{
	SDL_Rect* clip1 = new SDL_Rect;
	clip1->x = 0;
	clip1->y = 0;
	clip1->w = 64;
	clip1->h = 64;
	mClipList.Add(clip1);

	SDL_Rect* clip2 = new SDL_Rect;
	clip2->x = 0;
	clip2->y = 64;
	clip2->w = 64;
	clip2->h = 64;
	mClipList.Add(clip2);

	SDL_Rect* clip3 = new SDL_Rect;
	clip3->x = 0;
	clip3->y = 128;
	clip3->w = 64;
	clip3->h = 64;
	mClipList.Add(clip3);

	SDL_Rect* clip4 = new SDL_Rect;
	clip4->x = 0;
	clip4->y = 192;
	clip4->w = 64;
	clip4->h = 64;
	mClipList.Add(clip4);
	FRAMES_NUMBER = mClipList.GetSize();
}
