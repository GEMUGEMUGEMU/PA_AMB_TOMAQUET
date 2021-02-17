/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Hitbox.hpp
*  Purpose:
*  Creation Date: 11-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_HitBox_hpp
#define PAT_HitBox_hpp

#include "SDL2/SDL.h"
#include "PAT_Vector2D.hpp"

class PAT_CollidingObject;

class PAT_Hitbox
{
public:
	PAT_Hitbox();
	PAT_Hitbox(uint16_t x, uint16_t y);
	virtual ~PAT_Hitbox();
	void Notify();
	SDL_Rect* GetHitbox(PAT_Vector2D objectPosition);

	SDL_Rect mHitboxRectangle;

	//Relative coordinates of hitbox in base to hittable object
	uint16_t mX;
	uint16_t mY;
};

#endif /* PAT_HitBox_hpp */
