/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Sprite.hpp
*  Purpose: Adapter of Texture
*  Creation Date: 25-04-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Sprite_hpp
#define PAT_Sprite_hpp

#include "PAT.hpp"

struct PAT_Sprite
{
	enum STATUS {OK, E_PAT_UNINT, E_EMPTY_SURFACE, E_EMPTY_TEXTURE};

	PAT_Sprite();
	~PAT_Sprite();
	STATUS Init(SDL_Renderer* pRenderer);

	SDL_Texture* mTexture {nullptr};
	SDL_Rect* clip1 {nullptr};
};

#endif /* PAT_Sprite_hpp */
