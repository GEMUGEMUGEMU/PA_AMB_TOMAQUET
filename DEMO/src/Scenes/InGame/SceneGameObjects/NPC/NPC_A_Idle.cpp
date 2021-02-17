/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: NPC_A_Idle.cpp
*  Purpose:
*  Creation Date: 12-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "NPC_A_Idle.hpp"
#include "SDL2/SDL_image.h"

NPC_A_Idle::NPC_A_Idle() { }

NPC_A_Idle::~NPC_A_Idle()
{
	SDL_DestroyTexture(mAnimationSheet);
}

void NPC_A_Idle::LoadImage(SDL_Renderer* render)
{
	const char* filePath= "./src/Sprites/Prehistoric0.png";

	SDL_Surface * tempSurface = IMG_Load(filePath);

	mWith = tempSurface->w;
	mHeight = tempSurface->h;

	mAnimationSheet =
		SDL_CreateTextureFromSurface(render, tempSurface);

	SDL_FreeSurface(tempSurface);
}

void NPC_A_Idle::LoadClips()
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

	mFramesNumber = mClipList.GetSize();
}

