/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: AnimatedObject.cpp
*  Purpose: 
*  Creation Date: 05-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "AnimatedObject.h"

AnimatedObject::AnimatedObject() : mX(0), mY(0) {}


void AnimatedObject::Draw(SDL_Renderer* renderer)
{
	mAnimationManager.Draw(mX, mY, renderer);
}

void AnimatedObject::Init(int x, int y, const char* imagePath,
	SDL_Renderer* render)
{
	mX = x;
	mY = y;

	mAnimationManager.LoadImage(imagePath, render);
}
