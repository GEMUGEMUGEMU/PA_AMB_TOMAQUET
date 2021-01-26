/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PlayerMoveS.h
*  Purpose:
*  Creation Date: 26-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PlayerMoveS_h
#define PlayerMoveS_h

#include "PlayerState.h"
#include "Player.h"
//class Player;

class PlayerMoveS : public PlayerState
{
public:
	void Update(float deltaTime, Player* player)
	{
		player->mAnimationManager->UpdateFrame();
		player->Move(deltaTime);
	}
};

#endif /* PlayerMoveS_h */
