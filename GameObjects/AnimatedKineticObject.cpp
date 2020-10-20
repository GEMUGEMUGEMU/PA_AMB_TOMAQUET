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

/*
AnimatedKineticObject::Move(float deltaTime)
{
	if(mDirection.GetX() != 0 || mDirection.GetY() != 0)
	{
		Vector2D newPosition = mDirection * mSpeed * deltaTime;
		mRectangle->x += newPosition.GetX();
		mRectangle->y += newPosition.GetY();
		mDirection.SetX(0);
		mDirection.SetY(0);
	}
}
*/

AnimatedKineticObject::Update(float deltaTime)
{
	Move(deltaTime);
}
