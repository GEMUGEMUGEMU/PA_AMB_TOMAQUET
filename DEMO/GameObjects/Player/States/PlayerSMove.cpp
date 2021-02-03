/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PlayerSMove.cpp
*  Purpose:
*  Creation Date: 28-01-21
*  Created By: Andrea Andreu Salvagnin
*/
#include "PlayerSMove.h"

#include "PlayerSIdle.h"
#include "PlayerAIdle.h"

PlayerSMove::PlayerSMove(){}

PlayerSMove::~PlayerSMove(){}

void PlayerSMove::Draw(SDL_Renderer* renderer, Player* player)
{
	player->mAnimationManager.Draw(
		player->mPosition.GetX(),
		player->mPosition.GetY(),
		player->mAnimationManager.mAMove);
}

void PlayerSMove::Update(float deltaTime, Player* player)
{
	//TODO put switch case and move animation->update
	player->mAnimationManager.Update(player->mAnimationManager.mAMove);
	if(player->Move(deltaTime) == 1)
	{
		player->SetState(new PlayerSIdle);
//		player->SetAnimation(new PlayerAIdle);
	}
}


