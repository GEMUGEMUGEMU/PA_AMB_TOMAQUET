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
	const char* filePath= "./Fonts/YourQuotaRegular-z2zl.ttf";
//TTF_Init();
	SDL_Color textColor = { 0, 0, 0 };
	TTF_Font *font;
	//TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
	font = TTF_OpenFont( "./Fonts/YourQuotaRegular-z2zl.ttf", 28 );

	SDL_Surface * tempSurface = TTF_RenderText_Solid( font, "PAUSE", textColor );//IMG_Load(filePath);

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
/*
   void GraphicStaticObject::Draw(uint32_t x, uint32_t y, SDL_Renderer* renderer)
   {

   SDL_Color textColor = { 0, 0, 0 };
   SDL_RenderCopy( renderer, mSprite, mSpriteDimensions, mSpriteCordinates);
   }
 */
/*
   void PauseText::Init(uint32_t x, uint32_t y, SDL_Renderer* render)
   {
//TTF_Font *font = TTF_OpenFont( "./Fonts/YourQuotaRegular-z2zl.ttf", 28 );
//	TTF_Font *font = TTF_OpenFont( "YourQuotaRegular-z2zl.ttf", 28 );
SDL_Texture *font = TTF_OpenFont( "YourQuotaRegular-z2zl.ttf", 28 );
SDL_Color textColor = { 0, 0, 0 };


SDL_Surface * tempSurface = TTF_RenderText_Solid(font, "Pause", textColor);//IMG_Load(fontPath);

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
 */
