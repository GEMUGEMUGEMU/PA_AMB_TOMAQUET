/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Test1.h
*  Purpose:
*  Creation Date: 17-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Test1_h
#define Test1_h

#include "AnimatedStaticObject.h"

class Test1 : public AnimatedStaticObject
{
public:
	Test1() : AnimatedStaticObject() {}
	~Test1();
	void Init(int x, int y, SDL_Renderer* render);
	void Update(float deltaTime);
};

#endif /* Test1_h */
