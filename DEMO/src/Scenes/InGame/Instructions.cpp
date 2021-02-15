/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: Instructions.cpp
*  Purpose:
*  Creation Date: 11-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "Instructions.hpp"
#include "SDL_ttf.h"


Instructions::Instructions()
{

}

Instructions::~Instructions()
{

}

void Instructions::Init(uint32_t x, uint32_t y, SDL_Renderer* render)
{

	SDL_Color textColor = { 225, 225, 0 };
	TTF_Font *font;

	font = TTF_OpenFont( "./src/Fonts/YourQuotaRegular-z2zl.ttf", 25 );

	SDL_Surface * tempSurface = TTF_RenderText_Solid( font,
		"Press space for commands", textColor );

	mSpriteDimensions = new SDL_Rect;
	mSpriteDimensions->x = 0;
	mSpriteDimensions->y = 0;
	mSpriteDimensions->w = tempSurface->w;
	mSpriteDimensions->h = tempSurface->h;

	mSpriteCordinates = new SDL_Rect;
	mSpriteCordinates->x = x;
	mSpriteCordinates->y = y;
	mSpriteCordinates->w = tempSurface->w;
	mSpriteCordinates->h = tempSurface->h;

	mSprite = SDL_CreateTextureFromSurface(render, tempSurface);

	SDL_FreeSurface(tempSurface);

}

