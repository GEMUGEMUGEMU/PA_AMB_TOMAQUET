/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_StateObject.cpp
*  Purpose:
*  Creation Date: 03-02-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "PAT_StateObject.h"
#include "PAT_State.h"

void PAT_StateObject::SetState(PAT_State * newState)
{
	mState = newState;
}

