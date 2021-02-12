/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PAT_AnimatedKineticObject.hpp
*  Purpose:
*  Creation Date: 15-10-20
*  Created By: Andrea Andreu Salvagnin
*  Move in to DEMO
*/

#ifndef PAT_AnimatedKineticObject_hpp
#define PAT_AnimatedKineticObject_hpp

#include "SDL2/SDL.h"
#include "PAT_Vector2D.hpp"
#include "PAT_AnimatedObject.hpp"

class PAT_AnimatedKineticObject : public PAT_AnimatedObject
{
public:
	PAT_AnimatedKineticObject();
	virtual ~PAT_AnimatedKineticObject();

	virtual uint8_t Move(float deltaTime) = 0;

//protected:
	uint32_t mSpeed;
	PAT_Vector2D mDirection;
};

#endif /* PAT_AnimatedKineticObject_hpp */
