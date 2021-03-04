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

void Pl_S_Punch::Draw(/*SDL_Renderer* renderer,*/ Player* pPlayer)
{
	pPlayer->mAnimationManager.Draw(
		pPlayer->mPosition.GetX(),
		pPlayer->mPosition.GetY(),
		pPlayer->mAnimationManager.mAPunch);
}

void Pl_S_Punch::Update(float deltaTime, Player* pPlayer)
{
	if(pPlayer->mAnimationManager.Update(pPlayer->mAnimationManager.mAPunch)
		== 0)
	{
		pPlayer->SetState(new Pl_S_Idle);
	}
}


void Pl_S_Punch::Input(SDL_Event * pEvent, Player* pPlayer)
{
}
