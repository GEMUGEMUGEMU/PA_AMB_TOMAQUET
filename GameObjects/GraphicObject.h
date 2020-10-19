/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: GraphicObject.h
*  Purpose: 
*  Creation Date: 15-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef GraphicObject_h
#define GraphicObject_h
#include "SDL2/SDL.h"

class GraphicObject
{
public:
	GraphicObject(){}
	virtual ~GraphicObject(){}

	virtual void Draw(SDL_Renderer* renderer){}
};

#endif /* GraphicObject_h */
