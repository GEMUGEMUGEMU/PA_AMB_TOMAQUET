/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Window.cpp
*  Purpose:
*  Creation Date: 25-03-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "PAT_Window.hpp"

#ifdef DEBUG_MODE
#include <iostream>
#endif

PAT_Window::PAT_Window(SI height, SI width, const char* windowName) :
	mHeight(height), mWidth(width), mWindowName(windowName) { }

PAT_Window::~PAT_Window()
{
	Quit();
}

PAT_Window::STATUS PAT_Window::Init()
{

	if(PAT::WasInit() != 0)
	{
		return E_PAT_UNINT;
	}

	if( mWidth == 0 or mHeight == 0)
	{
		return WRONG_DIMENSINOS;
	}

	if( mWindowName == nullptr )
	{
		return WRONG_W_NAME;
	}

	mWindow = SDL_CreateWindow( mWindowName, SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, mWidth, mHeight, /*SDL_WINDOW_SHOWN*/
		SDL_WINDOW_MAXIMIZED);

	if(mWindow == nullptr)
	{
#ifdef DEBUG_MODE
		std::cout << "Error SDL Window initialization: "
			<< std::endl;
		std::cout << SDL_GetError() << std::endl;
#endif

		return INIT_ERROR;
	}

	mRenderer = SDL_CreateRenderer(mWindow,	-1, SDL_RENDERER_ACCELERATED
		| SDL_RENDERER_PRESENTVSYNC);

	if(mRenderer == nullptr)
	{
#ifdef DEBUG_MODE
		std::cout << "Error SDL Renderer initialization: "
			<< std::endl;
		std::cout << SDL_GetError() << std::endl;
#endif
		return RENDERER_ERROR;
	}

	SDL_SetRenderDrawColor(mRenderer, 0, 0, 255, 255 );

	mPixelFormat =
		SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);

	mCleanColor = SDL_MapRGBA( mPixelFormat, 0, 0, 255, 255);

	return OK;
}

PAT_Window::STATUS PAT_Window::Quit()
{
	if(mWindow == nullptr)
	{
		return QUIT_UNINT_WINDOW;
	}
	else
	{
		SDL_DestroyWindow( mWindow );
		return OK;
	}
}

void PAT_Window::Render()
{
	SDL_RenderPresent( mRenderer );

	//Wait two seconds
	SDL_Delay( 2000 );
}
