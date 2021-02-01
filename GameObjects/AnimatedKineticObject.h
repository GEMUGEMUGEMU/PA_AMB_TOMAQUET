/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: AnimatedKineticObject.h
*  Purpose:
*  Creation Date: 15-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef AnimatedKineticObject_h
#define AnimatedKineticObject_h

#include "SDL2/SDL.h"
#include "PAT_Vector2D.h"
#include "PAT_AnimationManager.h"
#include "GraphicObject.h"
#include "UpdateObject.h"

class AnimatedKineticObject : public GraphicObject, public UpdateObject
{
public:
//	AnimatedKineticObject() : mX(0), mY(0), mSpeed(0) {}
	AnimatedKineticObject() : mPosition(0,0), mSpeed(0) {}
	virtual ~AnimatedKineticObject(){}
	void Draw(SDL_Renderer* render);
//TODO: make pure virtual
	virtual void Init(float speed, uint32_t x, uint32_t y, SDL_Renderer * render) = 0;
	virtual void Init(float speed, PAT_Vector2D vector, SDL_Renderer * render) = 0;

//TODO: make pure virtual
	virtual void Update(float deltaTime){}
	virtual uint8_t Move(float deltaTime){}

	inline void SetDirection(PAT_Vector2D newDirection){mDirection = newDirection;}

	PAT_AnimationManager* mAnimationManager = nullptr;
protected:
	//in screen position
//	uint32_t mX, mY;

	uint32_t mSpeed;
	PAT_Vector2D mDirection;
	PAT_Vector2D mPosition;

};

#endif /* AnimatedKineticObject_h */
