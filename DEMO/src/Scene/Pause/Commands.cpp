/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: Commands.cpp
*  Purpose:
*  Creation Date: 11-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "Commands.hpp"
#include "SDL_ttf.h"


Commands::Commands()
{

}

Commands::~Commands()
{

}

void Commands::Init(uint32_t x, uint32_t y, SDL_Renderer* render)
{

	SDL_Color textColor = { 225, 225, 0 };
	TTF_Font *font;

	font = TTF_OpenFont( "./src/Fonts/YourQuotaRegular-z2zl.ttf", 25 );

	SDL_Surface * tempSurface = TTF_RenderText_Solid( font,
		"Arrows to move and p to punch", textColor );

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

