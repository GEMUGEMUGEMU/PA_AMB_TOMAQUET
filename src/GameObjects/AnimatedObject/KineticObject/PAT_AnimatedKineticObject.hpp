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
#include "PAT_AnimationManager.hpp"
#include "PAT_GraphicObject.hpp"
#include "PAT_UpdateObject.hpp"

class PAT_AnimatedKineticObject : public PAT_GraphicObject, public PAT_UpdateObject
{
public:
	PAT_AnimatedKineticObject();
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

#endif /* PAT_AnimatedKineticObject_hpp */
