/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PlayerSIdle.h
*  Purpose: Idle state of Player
*  Creation Date: 27-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PlayerSIdle_h
#define PlayerSIdle_h

#include "PlayerState.h"
#include "Player.h"


class PlayerSIdle : public PlayerState
{
public:
	PlayerSIdle();
	~PlayerSIdle();

	void Update(float deltaTime, Player* player);
};


#endif /* PlayerSIdle_h */
