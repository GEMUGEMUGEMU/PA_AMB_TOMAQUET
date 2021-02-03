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

void P_S_Punch::Draw(SDL_Renderer* renderer, PAT_AnimatedKineticObject * player)
{
	player->mAnimationManager->Draw(renderer);
}

void P_S_Punch::Update(float deltaTime, PAT_AnimatedKineticObject * player)
{
	if(player->mAnimationManager->Update())
	{
		player->SetState(new PlayerSIdle);
		player->SetAnimation(new PlayerSIdle);
	}
}

//void P_S_Punch::Update(float deltaTime, Player* player)
//{
//	if(player->mAnimationManager->Update())
//	{
//		player->SetState(new PlayerSIdle);
//		player->SetAnimation(new PlayerSIdle);
//	}
//}

//	if(player->DirectionIsNull())
//	{
//		player->mAnimationManager->Update();
//	}
//	else
//	{
//		player->SetState(new PlayerSMove);
//		player->SetAnimation(new P_A_Move);
//	}
