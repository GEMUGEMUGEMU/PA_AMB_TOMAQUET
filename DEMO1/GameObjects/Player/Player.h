/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Player.h
*  Purpose:
*  Creation Date: 27-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Player_h
#define Player_h

#include "AnimatedKineticObject.h"

class Player : public AnimatedKineticObject
{
public:
	Player() : AnimatedKineticObject() {}
	~Player();
	void Init(float speed, uint32_t x, uint32_t y, SDL_Renderer* render);
	void Move(float deltaTime);

	void Update(float deltaTime);

	void SetDirection(Vector2D newDirection);
};

#endif /* Player_h */
