/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PAT_AnimatedKineticObject.h
*  Purpose:
*  Creation Date: 15-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_AnimatedKineticObject_h
#define PAT_AnimatedKineticObject_h

#include "SDL2/SDL.h"
#include "PAT_Vector2D.h"
#include "PAT_AnimationManager.h"
#include "GraphicObject.h"
#include "UpdateObject.h"

class PAT_AnimatedKineticObject : public GraphicObject, public UpdateObject
{
public:
	PAT_AnimatedKineticObject() : mPosition(0,0), mSpeed(0) {}
	virtual ~PAT_AnimatedKineticObject(){}

	virtual void Init(float speed, PAT_Vector2D vector,
		SDL_Renderer * render) = 0;

	virtual void Update(float deltaTime) = 0;
	virtual uint8_t Move(float deltaTime) = 0;

	virtual void Draw(SDL_Renderer* render) = 0;

	PAT_Vector2D mPosition;

protected:
	uint32_t mSpeed;
	PAT_Vector2D mDirection;
};

#endif /* PAT_AnimatedKineticObject_h */
