/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: P_S_Punch.cpp
*  Purpose:
*  Creation Date: 01-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "P_S_Punch.h"
#include "PAT_AnimatedKineticObject.h"

P_S_Punch::P_S_Punch(){ }

P_S_Punch::~P_S_Punch(){ }

void P_S_Punch::Draw(SDL_Renderer* renderer, Player* player)
{
	player->mAnimationManager.Draw(
		player->mPosition.GetX(),
		player->mPosition.GetY(),
		player->mAnimationManager.mAMove);
}

void P_S_Punch::Update(float deltaTime, Player* player)
{
//TODO put switch case and move animation->update
	player->mAnimationManager.Update(player->mAnimationManager.mAMove);
	if(player->Move(deltaTime) == 1)
	{
		player->SetState(new PlayerSIdle);
	}
}


