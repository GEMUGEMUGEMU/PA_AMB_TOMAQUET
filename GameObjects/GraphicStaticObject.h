/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: GraphicStaticObject.h
*  Purpose:
*  Creation Date: 28-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef GraphicStaticObject_h
#define GraphicStaticObject_h

#include "GraphicObject.h"
#include "SDL2/SDL_image.h"


class GraphicStaticObject : public GraphicObject
{
public:
	GraphicStaticObject(){}
	virtual ~GraphicStaticObject(){}

	virtual void Init(uint32_t x, uint32_t y, SDL_Renderer* render){}
	void Draw(SDL_Renderer* renderer);
protected:
	SDL_Texture * mSprite = nullptr;
	SDL_Rect * mSpriteCordinates;
	SDL_Rect * mSpriteDimensions;
};

#endif /* GraphicStaticObject_h */
