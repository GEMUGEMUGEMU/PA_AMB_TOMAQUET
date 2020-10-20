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

class AnimatedKineticObject : public GraphicObject
{
public:
	AnimatedKineticObject() : mSpeed(0) {}
	virtual ~AnimatedKineticObject(){}

	void Draw(SDL_Renderer* render);

	inline void SetDirection(Vector2D newDirection){mDirection = newDirection;}
	virtual void Move(float deltaTime);
	void Update(float deltaTime);

private:
	uint32_t mSpeed;
	Vector2D mDirection;
};

#endif /* AnimatedKineticObject_h */
