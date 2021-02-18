/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Hurtbox.hpp
*  Purpose:
*  Creation Date: 18-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Hurtbox_hpp
#define PAT_Hurtbox_hpp

#include "SDL2/SDL.h"
#include "PAT_Vector2D.hpp"

class PAT_Hurtbox
{
public:
	PAT_Hurtbox(PAT_Vector2D position, uint32_t width, uint32_t height);
	virtual ~PAT_Hurtbox() = default;
	SDL_Rect* GetHurtbox(PAT_Vector2D objectPosition);

protected:
	const PAT_Vector2D mOffsetPosition;
	const uint32_t mWidth;
	const uint32_t mHeight;

	SDL_Rect mHurtboxArea;
};

#endif /* PAT_Hurtbox_hpp */
