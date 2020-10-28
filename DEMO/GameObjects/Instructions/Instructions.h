/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Instructions.h
*  Purpose:
*  Creation Date: 28-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Instructions_h
#define Instructions_h

#include "GraphicStaticObject.h"


class Instructions : public GraphicStaticObject
{
public:
	Instructions(){}

	~Instructions()
	{
		SDL_DestroyTexture(mSprite);
	}

	void Init(uint32_t x, uint32_t y, SDL_Renderer* render)
	{
		const char* filePath= "./Sprites/Instructions.png";

		SDL_Surface * tempSurface = IMG_Load(filePath);

		mSpriteCordinates = new SDL_Rect;
		mSpriteCordinates->x = 0;
		mSpriteCordinates->y = 0;
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
};

#endif /* Instructions_h */
