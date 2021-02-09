/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: Pl_S_Move.cpp
*  Purpose:
*  Creation Date: 28-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "Pl_S_Move.hpp"
#include "Pl_S_Idle.hpp"
#include "Pl_A_Idle.hpp"

Pl_S_Move::Pl_S_Move(){}

Pl_S_Move::~Pl_S_Move(){}

void Pl_S_Move::Draw(SDL_Renderer* renderer, Player* player)
{
	player->mAnimationManager.Draw(
		player->mPosition.GetX(),
		player->mPosition.GetY(),
		player->mAnimationManager.mAMove);
}

void Pl_S_Move::Update(float deltaTime, Player* player)
{
	//TODO put switch case and move animation->update
	player->mAnimationManager.Update(player->mAnimationManager.mAMove);
	player->Move(deltaTime);
}


void Pl_S_Move::Input(SDL_Event * event, Player* player)
{

	switch (event->type)
	{
		case SDL_KEYDOWN:
		{
			PAT_Vector2D movement;

			switch (event->key.keysym.sym)
			{
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
			}
		}
			break;
		case SDL_KEYUP:
			switch (event->key.keysym.sym)
			{
				case SDLK_UP:
				case SDLK_DOWN:
				case SDLK_LEFT:
				case SDLK_RIGHT:
					player->ResetMove();
					player->SetState(new Pl_S_Idle);
				break;
			}
		default:
			break;
	}
}

