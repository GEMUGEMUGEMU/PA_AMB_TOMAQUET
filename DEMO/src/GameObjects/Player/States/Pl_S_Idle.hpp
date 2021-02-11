/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: Pl_S_Idle.hpp
*  Purpose: Idle state of Player
*  Creation Date: 27-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Pl_S_Idle_hpp
#define Pl_S_Idle_hpp

#include "Pl_State.hpp"

class Pl_S_Idle : public Pl_State
{
public:
	Pl_S_Idle();
	~Pl_S_Idle();

	void Update(float deltaTime, Player* player) override;
	void Draw(SDL_Renderer* renderer, Player* player) override;
	void Input(SDL_Event * event, Player* player) override;
};

#endif /* Pl_S_Idle_hpp */
