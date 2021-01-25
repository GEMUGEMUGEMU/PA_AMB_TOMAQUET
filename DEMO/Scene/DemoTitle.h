/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: DemoTitle.h
*  Purpose: Show "PAUSE" text when pause
*  Creation Date: 10-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef DemoTitle_h
#define DemoTitle_h

#include "GraphicStaticObject.h"

class DemoTitle : public GraphicStaticObject
{
public:
	DemoTitle();
	~DemoTitle();

	void Init(uint32_t x, uint32_t y, SDL_Renderer* render);
//	void GraphicStaticObject::Draw(uint32_t x, uint32_t y, SDL_Renderer* renderer);
};

#endif /* DemoTitle_h */
