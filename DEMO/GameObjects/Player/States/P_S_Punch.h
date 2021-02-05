/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: P_S_Punch.h
*  Purpose:
*  Creation Date: 01-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef P_S_Punch_h
#define P_S_Punch_h

#include "PlayerState.h"

class P_S_Punch : public PlayerState
{
public:
	P_S_Punch();
	~P_S_Punch();


	void Update(float deltaTime, Player * player) override;
	void Draw(SDL_Renderer* renderer, Player* player) override;
};

#endif /* P_S_Punch_h */
