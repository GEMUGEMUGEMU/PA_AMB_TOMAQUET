/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PlayerSMove.h
*  Purpose:
*  Creation Date: 26-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PlayerSMove_h
#define PlayerSMove_h

#include "PlayerState.h"
#include "Player.h"


class PlayerSMove : public PlayerState
{
public:
	PlayerSMove();
	~PlayerSMove();

//	void Update(float deltaTime, Player* player);
	void Update(float deltaTime, Player * player) override;
	void Draw(SDL_Renderer* renderer, Player* player) override;
};

#endif /* PlayerSMove_h */
