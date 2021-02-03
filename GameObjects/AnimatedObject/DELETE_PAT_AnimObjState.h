/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_AnimObjState.h
*  Purpose: Abstract class used to implement state pattern
*  Creation Date: 02-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_AnimObjState_h
#define PAT_AnimObjState_h

#include "SDL2/SDL.h"
#include "PAT_State.h"
#include "PAT_AnimatedKineticObject.h"

class PAT_AnimObjState : public PAT_State
{
public:
	PAT_AnimObjState(){}
	virtual ~PAT_AnimObjState(){}

	virtual void Draw(SDL_Renderer* render,
		PAT_AnimatedKineticObject * object) = 0;
	virtual void Update(float deltaTime,
		PAT_AnimatedKineticObject * object) = 0;

//protected:
//	void ChangeState(PAT_AnimatedKineticObject * object,
//		PAT_AnimObjState* newState);
};



#endif /* PAT_AnimObjState_h */
