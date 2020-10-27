/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Test2.h
*  Purpose:
*  Creation Date: 17-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Test2_h
#define Test2_h

#include "AnimatedKineticObject.h"

class Test2 : public AnimatedKineticObject
{
public:
	Test2() : AnimatedKineticObject() {}
	~Test2();
	void Init(float speed, uint32_t x, uint32_t y, SDL_Renderer* render);
	void Move(float deltaTime);

	void Update(float deltaTime);

};

#endif /* Test2_h */
