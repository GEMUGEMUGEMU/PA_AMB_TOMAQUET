/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: NPC.cpp
*  Purpose:
*  Creation Date: 11-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "NPC.hpp"

NPC::NPC()
{
}
NPC::~NPC()
{
}

void NPC::Init(PAT_Vector2D newPosition, SDL_Renderer * renderer)
{
	mPosition = newPosition;
	mAnimationManager.Init(renderer);
}

void NPC::Draw(SDL_Renderer* renderer)
{
	mAnimationManager.Draw(mPosition.GetX(), mPosition.GetY(),
		mAnimationManager.mAIdle);
}

void NPC::Update(float deltaTime)
{
	mAnimationManager.Update(mAnimationManager.mAIdle);
}

PAT_Hitbox* NPC::GetHitbox()
{
	mHitbox.mHitboxRectangle.x = mPosition.GetX();
	mHitbox.mHitboxRectangle.y = mPosition.GetY();

	return &mHitbox;
}
