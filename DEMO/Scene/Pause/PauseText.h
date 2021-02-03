/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PauseText.h
*  Purpose: Show "PAUSE" text when pause
*  Creation Date: 10-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PauseText_h
#define PauseText_h

#include "GraphicStaticObject.h"

class PauseText : public GraphicStaticObject
{
public:
	PauseText();
	~PauseText();

	void Init(uint32_t x, uint32_t y, SDL_Renderer* render) override;
};

#endif /* PauseText_h */
