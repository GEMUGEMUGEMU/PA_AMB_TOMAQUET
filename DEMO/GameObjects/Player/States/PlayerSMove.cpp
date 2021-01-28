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

PlayerSMove::PlayerSMove(){}
PlayerSMove::~PlayerSMove(){}

void PlayerSMove::Update(float deltaTime, Player* player)
{
	player->mAnimationManager->UpdateFrame();
	player->Move(deltaTime);
	//TODO when finishes returns to Idle
}
