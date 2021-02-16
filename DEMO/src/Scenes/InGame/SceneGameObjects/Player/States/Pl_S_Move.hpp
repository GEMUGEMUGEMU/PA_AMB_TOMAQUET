/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: Pl_S_Move.hpp
*  Purpose:
*  Creation Date: 26-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Pl_S_Move_hpp
#define Pl_S_Move_hpp

#include "Pl_State.hpp"
#include "Player.hpp"


class Pl_S_Move : public Pl_State
{
public:
	Pl_S_Move();
	~Pl_S_Move();

	void Update(float deltaTime, Player * pPlayer) override;
	void Draw(/*SDL_Renderer* pRenderer,*/ Player* pPlayer) override;
	void Input(SDL_Event * pEvent, Player* pPlayer) override;
};

#endif /* Pl_S_Move_hpp */
