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

	virtual void Update(float deltaTime, Player* player) = 0;
	virtual void Draw(SDL_Renderer* renderer, Player* player) = 0;
	virtual void Input(SDL_Event * event, Player* player) = 0;

protected:
	void ChangeState(Player* player, Pl_State* newState);
};

#endif /* Pl_State_hpp */
