/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: Pl_A_Punch.cpp
*  Purpose:
*  Creation Date: 04-02-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "Pl_A_Punch.hpp"
#include "SDL2/SDL_image.h"

Pl_A_Punch::Pl_A_Punch() { }

Pl_A_Punch::~Pl_A_Punch()
{
	SDL_DestroyTexture(mAnimationSheet);
}

void Pl_A_Punch::LoadImage(SDL_Renderer* render)
{
	const char* filePath= "./Sprites/First_Punch.png";

	SDL_Surface * tempSurface = IMG_Load(filePath);

	mWith = tempSurface->w;
	mHeight = tempSurface->h;

	mAnimationSheet =
		SDL_CreateTextureFromSurface(render, tempSurface);

	SDL_FreeSurface(tempSurface);
}

void Pl_A_Punch::LoadClips()
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

	mFramesNumber = mClipList.GetSize();
}

