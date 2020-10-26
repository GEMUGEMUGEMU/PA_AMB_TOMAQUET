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
#include "Vector2D.h"
#include "GraphicObject.h"
#include "AnimationManager.h"

class AnimatedKineticObject : public GraphicObject
{
public:
	AnimatedKineticObject() : mX(0), mY(0), mSpeed(0) {}
	virtual ~AnimatedKineticObject(){}
	void Draw(SDL_Renderer* render);
	virtual void Init(float speed, uint32_t x, uint32_t y, SDL_Renderer * render){}


	void Update(float deltaTime);
	virtual void Move(float deltaTime){}


protected:
	AnimationManager* mAnimationManager = nullptr;
	//in screen position
	uint32_t mX, mY;

	inline void SetDirection(Vector2D newDirection){mDirection = newDirection;}
	uint32_t mSpeed;
	Vector2D mDirection;

};

#endif /* AnimatedKineticObject_h */
