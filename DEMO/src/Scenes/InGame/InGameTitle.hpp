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
#include "SDL2/SDL.h"
#include "PAT_Vector2D.hpp"

class InGameTitle : public PAT_GraphicStaticObject
{
public:
	InGameTitle(PAT_Vector2D position, SDL_Renderer* pRenderer);
	~InGameTitle();

	void Draw(SDL_Renderer* pRenderer) override;

	PAT_Vector2D mPosition;
};

#endif /* InGameTitle_hpp */
