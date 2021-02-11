/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: Instructions.hpp
*  Purpose:
*  Creation Date: 11-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Instructions_hpp
#define PAT_Instructions_hpp

#include "PAT_GraphicStaticObject.hpp"

class Instructions : public PAT_GraphicStaticObject
{
public:
	Instructions();
	~Instructions();

	void Init(uint32_t x, uint32_t y, SDL_Renderer* render);
};

#endif /* PAT_Instructions_hpp */
