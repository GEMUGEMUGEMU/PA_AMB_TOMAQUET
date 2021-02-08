/*
File Name: PAT_Screen.cpp
Purpose:
Creation Date: 06-09-20
Created By: Andrea Andreu Salvagnin
*/

#include "PAT_Screen.hpp"
#include "SDL2/SDL.h"


PAT_Screen::PAT_Screen(): mWidth(0), mHeight(0), mWindow(nullptr),
mWindowSurface(nullptr), mRenderer(nullptr), mPixelFormat(nullptr),
	mTexture(nullptr), mCleanColor(0)
{

}

PAT_Screen::~PAT_Screen()
{
	if(mPixelFormat)
	{
		SDL_FreeFormat(mPixelFormat);
		mPixelFormat = nullptr;
	}

	if(mTexture)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = nullptr;
	}

	if(mRenderer)
	{
		SDL_DestroyRenderer(mRenderer);
		mTexture = nullptr;
	}

	if(mWindow)
	{
		SDL_DestroyWindow(mWindow);
		mWindow = nullptr;
	}

	SDL_Quit();
}

SDL_Window* PAT_Screen::Init(uint32_t w, uint32_t h, const char* windowName)
{
	if(SDL_Init(SDL_INIT_VIDEO))
	{
		return nullptr;
	}

	mWidth = w;
	mHeight = h;

	mWindow = SDL_CreateWindow(windowName,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		mWidth, mHeight, 0);


	mRenderer = SDL_CreateRenderer(
			mWindow, -1,
			SDL_RENDERER_ACCELERATED
			| SDL_RENDERER_PRESENTVSYNC);

	if(mRenderer == nullptr)
	{
		return nullptr;
	}

	SDL_SetRenderDrawColor(mRenderer, 0,
		0, 255, 255 );

	mWindowSurface =
		SDL_GetWindowSurface(mWindow);

	mPixelFormat =
		SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);

	mCleanColor = SDL_MapRGBA(
			mPixelFormat,
			0,0,255,255);

	return mWindow;
}

void PAT_Screen::RenderClear()
{
	SDL_RenderClear( mRenderer );
}

void PAT_Screen::Render()
{
	SDL_RenderPresent( mRenderer );
}

SDL_Renderer* PAT_Screen::GetRenderer()
{
	return mRenderer;
}

