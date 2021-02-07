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
//#include "P_A_Move.h"
#include "P_S_Punch.h"

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
//	if(player->DirectionIsNull())
//	{
	//Prepare animation for next draw phase
	player->mAnimationManager.Update(player->mAnimationManager.mAIdle);
//	}
}


void PlayerSIdle::Input(SDL_Event * event, Player* player)
{
	switch (event->type)
	{
		case SDL_KEYDOWN:
		{
			PAT_Vector2D movement;

			switch (event->key.keysym.sym)
			{
				case SDLK_p:
					player->SetState(new P_S_Punch);
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

			switch (event->key.keysym.sym)
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
				player->SetDirection(movement);
				player->SetState(new PlayerSMove);
			}
		}
		break;

		default:
		break;
	}

}
