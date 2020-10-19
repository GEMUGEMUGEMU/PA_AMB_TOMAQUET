/*
File Name: Sprite.cpp
Purpose: 
Creation Date: 14-09-20
Created By: Andrea Andreu Salvagnin
*/
#include "Sprite.h"
#include <string>
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>

Sprite::Sprite(const char* spritePath)
{ 
	mSpriteSurface = IMG_Load(spritePath);
}

SDL_Surface* Sprite::GetSurface()
{
	return mSpriteSurface;
}
