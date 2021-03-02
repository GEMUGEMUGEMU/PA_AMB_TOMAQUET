/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_CollidingObject.hpp
*  Purpose:
*  Creation Date: 11-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_CollidingObject_hpp
#define PAT_CollidingObject_hpp

#include "PAT_Hitbox.hpp"
#include "PAT_GameObject.hpp"

class PAT_CollidingObject : public PAT_GameObject
{
public:
//	PAT_CollidingObject();
	virtual ~PAT_CollidingObject();

	virtual SDL_Rect* GetHitbox();
	void HasCollidedWith(SDL_Rect* pOtherHitbox);
	bool mHasCollided;// = false;

	PAT_Hitbox mHitbox;
	//PAT_Vector2D* mpRelativePosition;
	PAT_Vector2D& mrRelativePosition;
protected:
	PAT_CollidingObject(PAT_Vector2D& rPosition);
};

#endif /* PAT_CollidingObject_hpp */
