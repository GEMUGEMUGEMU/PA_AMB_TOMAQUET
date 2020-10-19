/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Test1.cpp
*  Purpose: Try animated static object in demo 
*  Creation Date: 16-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "Test1.h"
#include "Test1AnimationManager.h"

Test1::~Test1()
{
	delete mAnimationManager; 
}

void Test1::Init(int x, int y, SDL_Renderer* render)
{
	mAnimationManager = new Test1AnimationManager();
	mAnimationManager->Init(render);

	mX = x;
	mY = y;
}
