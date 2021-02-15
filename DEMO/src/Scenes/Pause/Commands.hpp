/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: Commands.hpp
*  Purpose:
*  Creation Date: 11-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Commands_hpp
#define Commands_hpp

#include "PAT_GraphicStaticObject.hpp"

class Commands : public PAT_GraphicStaticObject
{
public:
	Commands();
	~Commands();

	void Init(uint32_t x, uint32_t y, SDL_Renderer* render);
};



#endif /* Commands_hpp */
