/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PAT_GraphicObject.hpp
*  Purpose: Wraps visible objects
*  Creation Date: 15-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_GraphicObject_hpp
#define PAT_GraphicObject_hpp
#include "SDL2/SDL.h"

class PAT_GraphicObject
{
public:
	PAT_GraphicObject(){}
	virtual ~PAT_GraphicObject(){}

	virtual void Draw(SDL_Renderer* renderer){}
};

#endif /* PAT_GraphicObject_hpp */