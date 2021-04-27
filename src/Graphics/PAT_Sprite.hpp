/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Sprite.hpp
*  Purpose: Adapter of SDL_Texture used for sprites
*  Creation Date: 25-04-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Sprite_hpp
#define PAT_Sprite_hpp

#include <SDL2/SDL.h>
#include "PAT_Status.hpp"

namespace PAT
{

class Renderer;

struct Sprite
{
	Sprite();
	~Sprite();

	SDL_Texture* mSprite;

protected:
	PAT::Status InitSprite(/*SDL_Renderer*/ Renderer* pRenderer, const char* pFilePath);

};

}
#endif /* PAT_Sprite_hpp */
