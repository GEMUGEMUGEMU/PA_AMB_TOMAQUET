/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Hitbox.cpp
*  Purpose:
*  Creation Date: 12-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "PAT_Hitbox.hpp"
#include "PAT_Vector2D.hpp"


PAT_Hitbox::PAT_Hitbox(uint16_t x, uint16_t y) : mX(x), mY(x)
{
	mHitboxRectangle = {mX, mY, 64, 64};
}


PAT_Hitbox::PAT_Hitbox() : PAT_Hitbox(0, 0)
{
}

PAT_Hitbox::~PAT_Hitbox()
{
}

void PAT_Hitbox::Notify()
{
}


SDL_Rect* PAT_Hitbox::GetHitbox(PAT_Vector2D objectPosition)
{
	mHitboxRectangle.x = mX + objectPosition.GetX();
	mHitboxRectangle.y = mY + objectPosition.GetY();

	return &mHitboxRectangle;
}
