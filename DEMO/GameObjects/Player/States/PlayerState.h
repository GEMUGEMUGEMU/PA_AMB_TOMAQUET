/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PlayerState.h
*  Purpose:
*  Creation Date: 26-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PlayerState_h
#define PlayerState_h

class Player;

class PlayerState
{
public:
	PlayerState(){}
	virtual ~PlayerState(){}

	virtual void Update(float deltaTime, Player* player) =0;

};

#endif /* PlayerState_h */