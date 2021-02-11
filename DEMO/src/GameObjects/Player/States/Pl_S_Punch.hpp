/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: Pl_S_Punch.hpp
*  Purpose:
*  Creation Date: 01-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Pl_S_Punch_hpp
#define Pl_S_Punch_hpp

#include "Pl_State.hpp"
#include "Player.hpp"

class Pl_S_Punch : public Pl_State
{
public:
	Pl_S_Punch();
	~Pl_S_Punch();

	void Update(float deltaTime, Player * player) override;
	void Draw(SDL_Renderer* renderer, Player* player) override;
	void Input(SDL_Event * event, Player* player) override;
};

#endif /* Pl_S_Punch_hpp */
