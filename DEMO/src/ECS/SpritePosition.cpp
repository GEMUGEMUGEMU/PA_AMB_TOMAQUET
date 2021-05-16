/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: SpritePosition.cpp
*  Purpose:
*  Creation Date: 07-05-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "SpritePosition.hpp"

SpritePosition::SpritePosition(ECS::EntityID pEID) : PAT_Component(pEID) , mSpritePos(0,0,64,64)
{
//	mSpritePos.x = 0;
//	mSpritePos.y = 0;
//	mSpritePos.w = 64;
//	mSpritePos.h = 64;
}

SpritePosition::~SpritePosition()
{
}
