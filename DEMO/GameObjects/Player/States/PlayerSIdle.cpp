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
#include "P_A_Move.h"

PlayerSIdle::PlayerSIdle(){ }
PlayerSIdle::~PlayerSIdle(){ }

void PlayerSIdle::Draw(SDL_Renderer* renderer, Player* player)
{
	player->mAnimationManager.Draw(
		player->mPosition.GetX(),
		player->mPosition.GetY(),
		player->mAnimationManager.mAIdle);
}

void PlayerSIdle::Update(float deltaTime, Player* player)
{
	if(player->DirectionIsNull())
	{//Prepare animation
		player->mAnimationManager.Update(player->mAnimationManager.mAIdle);
	}
	else
	{//Set move state
		player->SetState(new PlayerSMove);
//		player->SetAnimation(new P_A_Move);
	}
}


//void PlayerSIdle::Update(float deltaTime, Player* player)
//{
//	if(player->DirectionIsNull())
//	{//Prepare animation
//		player->mAnimationManager->Update();
//	}
//	else
//	{//Set move state
//		player->SetState(new PlayerSMove);
//		player->SetAnimation(new P_A_Move);
//	}
//}
