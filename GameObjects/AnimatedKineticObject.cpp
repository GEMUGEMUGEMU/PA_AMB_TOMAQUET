/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: AnimatedKineticObject.cpp
*  Purpose:
*  Creation Date: 15-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "AnimatedKineticObject.h"

void AnimatedKineticObject::Draw(SDL_Renderer* renderer)
{
	mAnimationManager->Draw(mPosition.GetX(),
		mPosition.GetY(), renderer);
}
