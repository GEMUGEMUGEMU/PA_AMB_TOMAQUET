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

PAT_CollidingObject::PAT_CollidingObject(PAT_Vector2D& rPosition) : mHasCollided(false),
	mrRelativePosition(rPosition)
{

}

PAT_CollidingObject::~PAT_CollidingObject()
{

}

SDL_Rect* PAT_CollidingObject::GetHitbox()
{
	return mHitbox.GetHitbox(mrRelativePosition);
}

void PAT_CollidingObject::HasCollidedWith(SDL_Rect* pOtherHitbox)
{
	mHasCollided =
		SDL_HasIntersection(GetHitbox(), pOtherHitbox);
}
