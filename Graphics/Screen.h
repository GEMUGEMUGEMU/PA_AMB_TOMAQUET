/*
File Name: Screen.h
Purpose: 
Creation Date: 06-09-20
Created By: Andrea Andreu Salvagnin
*/

#ifndef Screen_h
#define Screen_h
#include "SDL2/SDL.h"
#include <stdint.h>

class Screen
{
public:
	Screen();
	~Screen();

	SDL_Window* Init(uint32_t w, uint32_t h, const char* windowName); 
	//void CleanSurface();
	SDL_Renderer* GetRenderer();

private:

	uint32_t mWidth;
	uint32_t mHeight;
	SDL_Window* mWindow;
	SDL_Surface* mWindowSurface;
	SDL_Renderer* mRenderer;
	SDL_PixelFormat* mPixelFormat;
	SDL_Texture* mTexture; 
	uint32_t mCleanColor;
		
};

#endif /* Screen_h */
