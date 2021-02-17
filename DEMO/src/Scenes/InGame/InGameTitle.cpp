/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: InGameTitle.cpp
*  Purpose:
*  Creation Date: 10-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "InGameTitle.hpp"
#include "SDL_ttf.h"


InGameTitle::InGameTitle(PAT_Vector2D position, SDL_Renderer* pRenderer) :
mPosition(position)
{
	SDL_Color text_color = { 225, 225, 0 };
	TTF_Font *font;

	font = TTF_OpenFont( "./src/Fonts/YourQuotaRegular-z2zl.ttf", 28 );

	SDL_Surface * text_surface = TTF_RenderText_Solid( font,
		"NISHIKIGOI DEMO", text_color );
	mpSprite = SDL_CreateTextureFromSurface(pRenderer, text_surface);
	SDL_FreeSurface(text_surface);

	mpSpriteDimensions = new SDL_Rect;
	mpSpriteDimensions->x = 0;
	mpSpriteDimensions->y = 0;
	mpSpriteDimensions->w = text_surface->w;
	mpSpriteDimensions->h = text_surface->h;

	mpSpriteCordinates = new SDL_Rect;
	mpSpriteCordinates->x = mPosition.GetX();
	mpSpriteCordinates->y = mPosition.GetY();
	mpSpriteCordinates->w = text_surface->w;
	mpSpriteCordinates->h = text_surface->h;
}

InGameTitle::~InGameTitle()
{

}

void InGameTitle::Draw(SDL_Renderer* pRenderer)
{
	SDL_RenderCopy( pRenderer, mpSprite, mpSpriteDimensions, mpSpriteCordinates);
}

