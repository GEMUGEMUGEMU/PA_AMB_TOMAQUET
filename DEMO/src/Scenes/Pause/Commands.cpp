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


Commands::Commands(PAT_Vector2D position, SDL_Renderer* pRenderer) :
mPosition(position)
{
	SDL_Color text_color = { 225, 225, 0 };
	TTF_Font *font;

	font = TTF_OpenFont( "./src/Fonts/YourQuotaRegular-z2zl.ttf", 25 );

	SDL_Surface * tempSurface = TTF_RenderText_Solid( font,
		"Arrows to move and p to punch", text_color );

	mpSpriteDimensions = new SDL_Rect;
	mpSpriteDimensions->x = 0;
	mpSpriteDimensions->y = 0;
	mpSpriteDimensions->w = tempSurface->w;
	mpSpriteDimensions->h = tempSurface->h;

	mpSpriteCordinates = new SDL_Rect;
	mpSpriteCordinates->x = mPosition.GetX();
	mpSpriteCordinates->y = mPosition.GetY();
	mpSpriteCordinates->w = tempSurface->w;
	mpSpriteCordinates->h = tempSurface->h;

	mpSprite = SDL_CreateTextureFromSurface(pRenderer, tempSurface);

	SDL_FreeSurface(tempSurface);
}

Commands::~Commands()
{

}

void Commands::Draw(SDL_Renderer* pRenderer)
{
	SDL_RenderCopy( pRenderer, mpSprite, mpSpriteDimensions, mpSpriteCordinates);
}

