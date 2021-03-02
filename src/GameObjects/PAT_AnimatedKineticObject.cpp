/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_AnimatedKineticObject.cpp
*  Purpose:
*  Creation Date: 08-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "PAT_AnimatedKineticObject.hpp"

PAT_AnimatedKineticObject::PAT_AnimatedKineticObject(uint32_t speed) :
	mSpeed(speed), mDirection(PAT_Vector2D(0, 0))
{

}

PAT_AnimatedKineticObject::~PAT_AnimatedKineticObject()
{

}
