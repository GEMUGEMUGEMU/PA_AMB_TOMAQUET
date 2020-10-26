/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Test2.cpp
*  Purpose: Try animated static object in demo
*  Creation Date: 16-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "Test2.h"
#include "Test2AnimationManager.h"
#include "Vector2D.h"

Test2::~Test2()
{
	delete mAnimationManager;
}

void Test2::Init(float speed, uint32_t x, uint32_t y, SDL_Renderer* render)
{
	mSpeed = speed;
	mAnimationManager = new Test2AnimationManager();
	mAnimationManager->Init(render);

	mX = x;
	mY = y;
}

void Test2::Move(float deltaTime)
{
	if(mDirection.GetX() != 0 || mDirection.GetY() != 0)
	{
		Vector2D newPosition = mDirection * mSpeed * deltaTime;

		mX = newPosition.GetX();
		mY = newPosition.GetY();

		//Clean direction
		mDirection.SetX(0);
		mDirection.SetY(0);
	}
}
