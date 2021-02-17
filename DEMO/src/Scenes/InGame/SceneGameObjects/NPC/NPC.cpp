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

NPC::NPC(PAT_Vector2D position) : PAT_CollidingObject(mPosition),
	mPosition(position)
{

}

NPC::~NPC()
{

}

void NPC::Init(SDL_Renderer * pRenderer)
{
	mAnimationManager.Init(pRenderer);
}

void NPC::Draw(SDL_Renderer* pRenderer)
{
	mAnimationManager.Draw(mPosition.GetX(), mPosition.GetY(),
		mAnimationManager.mAIdle);
}

void NPC::Update(float deltaTime)
{
	mAnimationManager.Update(mAnimationManager.mAIdle);
}

