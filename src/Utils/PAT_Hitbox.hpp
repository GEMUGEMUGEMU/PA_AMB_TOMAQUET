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

class PAT_HittableObject;

class PAT_Hitbox
{
public:
	PAT_Hitbox()
	{
		mHitboxRectangle = {64, 64, 0, 0};
		mHitboxRectangle.h = 64;
		mHitboxRectangle.w = 64;
		mHitboxRectangle.x = 0;
		mHitboxRectangle.y = 0;
	}
	virtual ~PAT_Hitbox(){ }
	void Notify(){}

	PAT_HittableObject* owner;
	SDL_Rect mHitboxRectangle;
};

#endif /* PAT_HitBox_hpp */
