/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: DemoTitle.cpp
*  Purpose:
*  Creation Date: 10-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "DemoTitle.hpp"
#include "SDL_ttf.h"


DemoTitle::DemoTitle()
{

}

DemoTitle::~DemoTitle()
{

}

void DemoTitle::Init(uint32_t x, uint32_t y, SDL_Renderer* render)
{

	SDL_Color textColor = { 225, 225, 0 };
	TTF_Font *font;

	font = TTF_OpenFont( "./src/Fonts/YourQuotaRegular-z2zl.ttf", 40 );

	SDL_Surface * tempSurface = TTF_RenderText_Solid( font, "NISHIKIGOI DEMO", textColor );

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

