/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: DemoTitle.hpp
*  Purpose: Show "PAUSE" text when pause
*  Creation Date: 10-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef DemoTitle_hpp
#define DemoTitle_hpp

#include "PAT_GraphicStaticObject.hpp"

class DemoTitle : public PAT_GraphicStaticObject
{
public:
	DemoTitle();
	~DemoTitle();

	void Init(uint32_t x, uint32_t y, SDL_Renderer* render);
};

#endif /* DemoTitle_hpp */
