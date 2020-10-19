/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: AnimatedObject.h
*  Purpose: 
*  Creation Date: 05-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef AnimatedObject_h
#define AnimatedObject_h

#include "AnimationManager.h"

class AnimatedObject
{
public:
	AnimatedObject();
	void Draw(SDL_Renderer* renderer);
	void Init(int x, int y, const char* imagePath, SDL_Renderer* render);
private:
	AnimationManager mAnimationManager;
	int mX, mY;
};

#endif /* AnimatedObject_h */
