/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: Pl_S_Punch.cpp
*  Purpose:
*  Creation Date: 01-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "Pl_S_Punch.hpp"
#include "Pl_S_Idle.hpp"

Pl_S_Punch::Pl_S_Punch(){ }

Pl_S_Punch::~Pl_S_Punch(){ }

void Pl_S_Punch::Draw(SDL_Renderer* renderer, Player* player)
{
	player->mAnimationManager.Draw(
		player->mPosition.GetX(),
		player->mPosition.GetY(),
		player->mAnimationManager.mAPunch);
}

void Pl_S_Punch::Update(float deltaTime, Player* player)
{
	if(player->mAnimationManager.Update(player->mAnimationManager.mAPunch)
		== 0)
	{
		player->SetState(new Pl_S_Idle);
	}
}


void Pl_S_Punch::Input(SDL_Event * event, Player* player)
{
}
