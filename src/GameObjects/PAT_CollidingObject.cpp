/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_CollidingObject.cpp
*  Purpose:
*  Creation Date: 12-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "PAT_CollidingObject.hpp"

PAT_CollidingObject::PAT_CollidingObject() : mRelativePosition(nullptr)
{

}

PAT_CollidingObject::~PAT_CollidingObject()
{
	mRelativePosition = nullptr;
}

//PAT_Hitbox* PAT_CollidingObject::GetHitbox() { }

SDL_Rect* PAT_CollidingObject::GetHitbox()
{
	return hitbox.GetHitbox(*mRelativePosition);
}

void PAT_CollidingObject::HasCollidedWith(SDL_Rect* otherHitbox)
{
	mHasCollided =
		SDL_HasIntersection(GetHitbox(), otherHitbox);
}
