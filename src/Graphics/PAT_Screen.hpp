/*
File Name: PAT_Screen.hpp
Purpose:
Creation Date: 06-09-20
Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Screen_hpp
#define PAT_Screen_hpp
#include "SDL2/SDL.h"
#include <stdint.h>

class PAT_Screen
{
public:
	PAT_Screen();
	~PAT_Screen();

	SDL_Window* Init(uint32_t w, uint32_t h, const char* windowName);
	void RenderClear();
	void Render();
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

#endif /* PAT_Screen_hpp */
