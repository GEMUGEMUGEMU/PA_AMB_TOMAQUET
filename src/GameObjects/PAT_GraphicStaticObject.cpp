/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PAT_GraphicStaticObject.cpp
*  Purpose:
*  Creation Date: 28-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "PAT_GraphicStaticObject.hpp"

PAT_GraphicStaticObject::PAT_GraphicStaticObject()
{

}

PAT_GraphicStaticObject::~PAT_GraphicStaticObject()
{
	SDL_DestroyTexture(mSprite);
}

void PAT_GraphicStaticObject::Draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy( renderer, mSprite, mSpriteDimensions, mSpriteCordinates);
}
