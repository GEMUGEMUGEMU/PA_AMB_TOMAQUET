/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PauseText.hpp
*  Purpose: Show "PAUSE" text when pause
*  Creation Date: 10-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PauseText_hpp
#define PauseText_hpp

#include "PAT_GraphicStaticObject.hpp"

class PauseText : public PAT_GraphicStaticObject
{
public:
	PauseText();
	~PauseText();

	void Init(uint32_t x, uint32_t y, SDL_Renderer* render) override;
};

#endif /* PauseText_hpp */
