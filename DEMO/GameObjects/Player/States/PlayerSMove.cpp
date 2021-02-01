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

void PlayerSMove::Update(float deltaTime, Player* player)
{
	player->mAnimationManager->Update();
	if(player->Move(deltaTime) == 1)
	{
		player->SetState(new PlayerSIdle);
		player->SetAnimation(new PlayerAIdle);
	}
}
