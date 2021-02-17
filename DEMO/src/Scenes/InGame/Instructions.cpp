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


Instructions::Instructions(PAT_Vector2D position, SDL_Renderer* pRenderer) :
mPosition(position)
{
	SDL_Color text_color = { 225, 225, 0 };
	TTF_Font *font;

	font = TTF_OpenFont( "./src/Fonts/YourQuotaRegular-z2zl.ttf", 28 );

	SDL_Surface * text_surface = TTF_RenderText_Solid( font,
		"Press space for commands", text_color );
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

Instructions::~Instructions()
{

}

void Instructions::Draw(SDL_Renderer* pRenderer)
{
	SDL_RenderCopy( pRenderer, mpSprite, mpSpriteDimensions, mpSpriteCordinates);
}

