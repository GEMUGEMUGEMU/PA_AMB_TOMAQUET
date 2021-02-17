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
#include "PAT_Vector2D.hpp"
#include "SDL2/SDL.h"

class Instructions : public PAT_GraphicStaticObject
{
public:
	Instructions(PAT_Vector2D position, SDL_Renderer* pRenderer);
	~Instructions();

	void Draw(SDL_Renderer* pRenderer);

	PAT_Vector2D mPosition;
};

#endif /* PAT_Instructions_hpp */
