/*
File Name: PAT_Sprite.hpp
Purpose:
Creation Date: 14-09-20
Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Sprite_hpp
#define PAT_Sprite_hpp
#include <string>
#include "SDL2/SDL.h"

class PAT_Sprite
{
public:
	PAT_Sprite(const char* spritePath);
	~PAT_Sprite(){}

	SDL_Surface* GetSurface();

private:
	SDL_Surface* mSpriteSurface;
};
#endif /* PAT_Sprite_hpp */
