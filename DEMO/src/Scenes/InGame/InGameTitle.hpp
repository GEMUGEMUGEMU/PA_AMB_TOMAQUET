/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: InGameTitle.hpp
*  Purpose: Show "PAUSE" text when pause
*  Creation Date: 10-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef InGameTitle_hpp
#define InGameTitle_hpp

#include "PAT_GraphicStaticObject.hpp"

class InGameTitle : public PAT_GraphicStaticObject
{
public:
	InGameTitle();
	~InGameTitle();

	void Init(uint32_t x, uint32_t y, SDL_Renderer* render);
};

#endif /* InGameTitle_hpp */
