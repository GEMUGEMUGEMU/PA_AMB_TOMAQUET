/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Hurtbox.cpp
*  Purpose:
*  Creation Date: 18-02-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "PAT_Hurtbox.hpp"

PAT_Hurtbox::PAT_Hurtbox(PAT_Vector2D position, uint32_t width,
uint32_t height) :
mOffsetPosition(position), mWidth(width), mHeight(height)
{

}


SDL_Rect* PAT_Hurtbox::GetHurtbox(PAT_Vector2D objectPosition)
{
	PAT_Vector2D relative_pos = mOffsetPosition + objectPosition;
	mHurtboxArea={relative_pos.GetX(),relative_pos.GetY(), mWidth, mHeight};
	return &mHurtboxArea;
}
