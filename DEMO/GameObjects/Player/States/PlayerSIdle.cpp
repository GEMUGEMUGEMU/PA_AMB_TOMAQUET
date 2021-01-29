/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PlayerSIdle.cpp
*  Purpose:
*  Creation Date: 28-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "PlayerSIdle.h"
#include "PlayerSMove.h"

PlayerSIdle::PlayerSIdle(){ }
PlayerSIdle::~PlayerSIdle(){ }

void PlayerSIdle::Update(float deltaTime, Player* player)
{
	if(player->DirectionIsNotNull())
	{
		//player->mAnimationManager->UpdateFrame();
		player->mAnimationManager->Update();
	}
	else
	{
		player->SetState(new PlayerSMove);
	}
}
