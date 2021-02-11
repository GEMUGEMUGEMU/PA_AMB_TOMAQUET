/*
File Name: PAT_Sprite.cpp
Purpose:
Creation Date: 14-09-20
Created By: Andrea Andreu Salvagnin
*/
#include "PAT_Sprite.hpp"
#include <string>
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>

PAT_Sprite::PAT_Sprite(const char* spritePath)
{
	mSpriteSurface = IMG_Load(spritePath);
}

SDL_Surface* PAT_Sprite::GetSurface()
{
	return mSpriteSurface;
}
