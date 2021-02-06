/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: AnimatedStaticObject.h
*  Purpose:
*  Creation Date: 15-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef AnimatedStaticObject_h
#define AnimatedStaticObject_h

#include "GraphicObject.h"
#include "PAT_AnimationManager.h"
#include "UpdateObject.h"

class AnimatedStaticObject : public GraphicObject, public UpdateObject
{
public:
	AnimatedStaticObject(): mX(0) , mY(0) {}
	virtual ~AnimatedStaticObject(){}
	void Draw(SDL_Renderer* renderer);
	virtual void Init(int x, int y, SDL_Renderer* render){}
	virtual void Update(){}

protected:
	PAT_AnimationManager* mAnimationManager;
	//In screen position
	uint32_t mX, mY;

};

#endif /* AnimatedStaticObject_h */