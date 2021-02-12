/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PAT_GraphicStaticObject.hpp
*  Purpose:
*  Creation Date: 28-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_GraphicStaticObject_hpp
#define PAT_GraphicStaticObject_hpp

#include "PAT_GraphicObject.hpp"
#include "SDL2/SDL_image.h"


class PAT_GraphicStaticObject : public PAT_GraphicObject
{
public:
	PAT_GraphicStaticObject();
	virtual ~PAT_GraphicStaticObject();
	void Draw(SDL_Renderer* renderer);

protected:
	SDL_Texture * mSprite = nullptr;
	SDL_Rect * mSpriteCordinates = nullptr;
	SDL_Rect * mSpriteDimensions = nullptr;
};

#endif /* PAT_GraphicStaticObject_hpp */
