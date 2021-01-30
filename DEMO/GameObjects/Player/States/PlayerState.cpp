/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PlayerState.cpp
*  Purpose:
*  Creation Date: 28-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "PlayerState.h"
#include "Player.h"

PlayerState::PlayerState(){ }

void PlayerState::Update(float deltaTime, Player* player){ }

//void PlayerState::Move(){ }

void PlayerState::ChangeState(Player* player, PlayerState* newState)
{
	player->SetState(newState);
}


