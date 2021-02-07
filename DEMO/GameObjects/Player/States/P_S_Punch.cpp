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
#include "PlayerSIdle.h"
//#include "PAT_AnimatedKineticObject.h"

P_S_Punch::P_S_Punch(){ }

P_S_Punch::~P_S_Punch(){ }

void P_S_Punch::Draw(SDL_Renderer* renderer, Player* player)
{
	player->mAnimationManager.Draw(
		player->mPosition.GetX(),
		player->mPosition.GetY(),
		player->mAnimationManager.mAPunch);
}

void P_S_Punch::Update(float deltaTime, Player* player)
{
	if(player->mAnimationManager.Update(player->mAnimationManager.mAPunch)
		== 0)
	{
		player->SetState(new PlayerSIdle);
	}
}


void P_S_Punch::Input(SDL_Event * event, Player* player)
{
}
