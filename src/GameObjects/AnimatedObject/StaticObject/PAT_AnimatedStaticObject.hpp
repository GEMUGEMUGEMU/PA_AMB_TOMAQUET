/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PAT_AnimatedStaticObject.hpp
*  Purpose:
*  Creation Date: 15-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_AnimatedStaticObject_hpp
#define PAT_AnimatedStaticObject_hpp

#include "PAT_GraphicObject.hpp"
#include "PAT_AnimationManager.hpp"
#include "PAT_UpdateObject.hpp"

class PAT_AnimatedStaticObject : public PAT_GraphicObject, public PAT_UpdateObject
{
public:
	PAT_AnimatedStaticObject(): mX(0) , mY(0) {}
	virtual ~PAT_AnimatedStaticObject(){}
	virtual void Draw(SDL_Renderer* renderer) = 0;
	virtual void Init(int x, int y, SDL_Renderer* render) = 0;
	virtual void Update() = 0;

protected:
//	PAT_AnimationManager* mAnimationManager;
	//In screen position
	uint32_t mX, mY;

};

#endif /* PAT_AnimatedStaticObject_hpp */
