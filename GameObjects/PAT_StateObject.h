/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_StateObject.h
*  Purpose: An object for state pattern .
*  Creation Date: 03-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_StateObject_h
#define PAT_StateObject_h

#include "PAT_State.h"

class PAT_StateObject
{
public:
	PAT_StateObject(){}
	virtual ~PAT_StateObject(){}

	void SetState(PAT_State * newState);

protected:
	PAT_State * mState = nullptr;
};

#endif /* PAT_StateObject_h */
