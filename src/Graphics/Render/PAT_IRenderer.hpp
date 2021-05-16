/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_IRenderer.hpp
*  Purpose: Interface for a PAT Renderer
*  Creation Date: 08-05-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_IRenderer_hpp
#define PAT_IRenderer_hpp

#include <SDL2/SDL.h>
#include "PAT_Rect.hpp"
#include "PAT_Sprite.hpp"

namespace PAT
{

using namespace SDLA;
//struct Sprite;

struct IRenderer
{
	virtual ~IRenderer() = default;
	virtual void Render() = 0;
	virtual void Clean() = 0;
	virtual void AddToRender(Sprite* pSprite, Rect* pClip) = 0;

};

}
#endif /* PAT_IRenderer_hpp */