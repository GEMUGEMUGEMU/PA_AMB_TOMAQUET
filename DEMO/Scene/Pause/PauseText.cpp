/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PauseText.cpp
*  Purpose:
*  Creation Date: 10-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "PauseText.h"
#include "SDL_ttf.h"


PauseText::PauseText()
{

}

PauseText::~PauseText()
{

}

void PauseText::Init(uint32_t x, uint32_t y, SDL_Renderer* render)
{

	SDL_Color textColor = { 225, 225, 0 };
	TTF_Font *font;

	font = TTF_OpenFont( "./Fonts/YourQuotaRegular-z2zl.ttf", 28 );

	SDL_Surface * tempSurface = TTF_RenderText_Solid( font, "PAUSE",
		textColor );

	mTextureDimensions = new SDL_Rect;
	mTextureDimensions->x = 0;
	mTextureDimensions->y = 0;
	mTextureDimensions->w = tempSurface->w;
	mTextureDimensions->h = tempSurface->h;

	mTextureCordinates = new SDL_Rect;
	mTextureCordinates->x = x;
	mTextureCordinates->y = y;
	mTextureCordinates->w = tempSurface->w;
	mTextureCordinates->h = tempSurface->h;

	mTexture = SDL_CreateTextureFromSurface(render, tempSurface);

	SDL_FreeSurface(tempSurface);

}
