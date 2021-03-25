/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Sprite.cpp
*  Purpose:
*  Creation Date: 25-04-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "PAT_Sprite.hpp"

PAT_Sprite::PAT_Sprite()
{
}

PAT_Sprite::~PAT_Sprite()
{
	SDL_DestroyTexture(mTexture);
}

PAT_Sprite::STATUS PAT_Sprite::Init(SDL_Renderer* pRenderer)
{
	if(PAT::WasInit() != 0)
	{
		return E_PAT_UNINT;
	}

	const char* filePath= "./sprites/Prehistoric0.png";

	SDL_Surface * tempSurface = IMG_Load(filePath);

	mTexture =
		SDL_CreateTextureFromSurface(pRenderer, tempSurface);

	SDL_FreeSurface(tempSurface);

	clip1 = new SDL_Rect;
	clip1->x = 0;
	clip1->y = 0;
	clip1->w = 64;
	clip1->h = 64;

	return OK;
}

//constexpr
