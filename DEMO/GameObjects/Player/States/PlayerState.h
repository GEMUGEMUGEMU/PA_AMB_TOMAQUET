/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PlayerState.h
*  Purpose: Abstract class used to implement STATE pattern for player
*  Creation Date: 26-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PlayerState_h
#define PlayerState_h

#include "PAT_State.h"
#include "SDL2/SDL.h"

class Player;

class PlayerState :  public PAT_State
{
public:
	PlayerState();
	virtual ~PlayerState(){}

	virtual void Update(float deltaTime, Player* player) = 0;
	virtual void Draw(SDL_Renderer* renderer, Player* player) = 0;
//	virtual void Move();

protected:
	void ChangeState(Player* player, PlayerState* newState);
};

#endif /* PlayerState_h */
