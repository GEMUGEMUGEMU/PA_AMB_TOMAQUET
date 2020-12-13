/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: GraphicStaticObject.cpp
*  Purpose:
*  Creation Date: 28-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "GraphicStaticObject.h"

void GraphicStaticObject::Draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy( renderer, mTexture, mTextureDimensions,
		mTextureCordinates);
}
