/*
File Name: Sprite.h
Purpose: 
Creation Date: 14-09-20
Created By: Andrea Andreu Salvagnin
*/

#ifndef Sprite_h
#define Sprite_h
#include <string>
#include "SDL2/SDL.h"

class Sprite
{
public:
	Sprite(const char* spritePath);
	~Sprite(){}

	SDL_Surface* GetSurface();

private:
	SDL_Surface* mSpriteSurface;
};
#endif /* Sprite_h */
