/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: Pl_State.hpp
*  Purpose: Abstract class used to implement STATE pattern for player
*  Creation Date: 26-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Pl_State_hpp
#define Pl_State_hpp

#include "SDL2/SDL.h"

class Player;

class Pl_State
{
public:
	Pl_State();
	virtual ~Pl_State(){}

	virtual void Update(float deltaTime, Player* pPlayer) = 0;
	virtual void Draw(/*SDL_Renderer* renderer,*/ Player* pPlayer) = 0;
	virtual void Input(SDL_Event * pEvent, Player* pPlayer) = 0;

protected:
	void ChangeState(Player* pPlayer, Pl_State* pNewState);
};

#endif /* Pl_State_hpp */
