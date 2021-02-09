/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: Pl_State.cpp
*  Purpose:
*  Creation Date: 28-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "Player.hpp"

Pl_State::Pl_State(){ }

void Pl_State::ChangeState(Player* player, Pl_State* newState)
{
	player->SetState(newState);
}


