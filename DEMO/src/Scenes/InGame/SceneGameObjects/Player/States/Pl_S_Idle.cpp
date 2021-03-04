/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: Pl_S_Idle.cpp
*  Purpose:
*  Creation Date: 28-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "Pl_S_Idle.hpp"
#include "Pl_S_Move.hpp"
#include "Pl_S_Punch.hpp"

Pl_S_Idle::Pl_S_Idle(){ }
Pl_S_Idle::~Pl_S_Idle(){ }

void Pl_S_Idle::Draw( Player* pPlayer)
{
	pPlayer->mAnimationManager.Draw(
		pPlayer->mPosition.GetX(),
		pPlayer->mPosition.GetY(),
		pPlayer->mAnimationManager.mAIdle);
}

void Pl_S_Idle::Update(float deltaTime, Player* pPlayer)
{
	pPlayer->mAnimationManager.Update(pPlayer->mAnimationManager.mAIdle);
}


void Pl_S_Idle::Input(SDL_Event * pEvent, Player* pPlayer)
{
	switch (pEvent->type)
	{
		case SDL_KEYDOWN:
		{
			PAT_Vector2D movement(0, 0);

			switch (pEvent->key.keysym.sym)
			{
				case SDLK_p:
					pPlayer->SetState(new Pl_S_Punch);
					return;

				case SDLK_UP:
				{
					PAT_Vector2D up(0, -1);
					movement = movement + up;
				}
				break;

				case SDLK_DOWN:
				{
					PAT_Vector2D down(0, 1);
					movement = movement + down;
				}
				break;
			}

			switch (pEvent->key.keysym.sym)
			{
				case SDLK_LEFT:
				{
					PAT_Vector2D left(-1, 0);
					movement = movement + left;
				}
				break;

				case SDLK_RIGHT:
				{
					PAT_Vector2D right(1, 0);
					movement = movement + right;
				}
				break;
			}


			if(!movement.EqualsVectorZero())
			{
				movement.Normalize();
				pPlayer->SetDirection(movement);
				pPlayer->SetState(new Pl_S_Move);
			}
		}
		break;

		default:
		break;
	}

}
