/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_HittableObject.hpp
*  Purpose:
*  Creation Date: 11-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_HittableObject_hpp
#define PAT_HittableObject_hpp

#include "PAT_Hitbox.hpp"

class PAT_HittableObject
{
public:
	PAT_HittableObject() { }
	~PAT_HittableObject() { }
	virtual PAT_Hitbox*  GetHitbox() = 0;
//	virtual void NotifyHasCollided() = 0;
};

#endif /* PAT_HittableObject_hpp */
