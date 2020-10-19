/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: AnimatedStaticObject.cpp
*  Purpose: 
*  Creation Date: 15-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "AnimatedStaticObject.h"

AnimatedStaticObject::AnimatedStaticObject() : mX(0) , mY(0) {}

void AnimatedStaticObject::Draw(SDL_Renderer* renderer)
{
	mAnimationManager->Draw(mX, mY, renderer);
}

