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
		SDL_DestroyTexture(mTexture);
	}

	void Init(uint32_t x, uint32_t y, SDL_Renderer* render)
	{
		const char* filePath= "./Sprites/Instructions.png";

		SDL_Surface * tempSurface = IMG_Load(filePath);

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
};

#endif /* Instructions_h */
