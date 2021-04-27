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
#include "PAT_Renderer_SDL2.hpp"

#ifdef DEBUG_MODE
#include <iostream>
#endif

PAT_Window::PAT_Window(SI height, SI width, const char* windowName) :
	mHeight(height), mWidth(width), mWindowName(windowName) { }

PAT_Window::~PAT_Window()
{
	FreePixelFormat();

	DeleteSDLWindow();
}

PAT_Window::STATUS PAT_Window::Init()
{

	if(PAT_System::WasInit() != 0)
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

	SDL_Renderer* renderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED
		| SDL_RENDERER_PRESENTVSYNC);

	if(renderer == nullptr)
	{
#ifdef DEBUG_MODE
		std::cout << "Error SDL Renderer initialization: "
			<< std::endl;
		std::cout << SDL_GetError() << std::endl;
#endif
		return RENDERER_ERROR;
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255 );

	PAT::SDL2A::RendererAdapter renderer_adapter(renderer);

	mRenderer = PAT::Renderer(renderer_adapter);

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
		FreePixelFormat();

		DeleteSDLWindow();

		return OK;
	}
}

void PAT_Window::Render()
{
	mRenderer.Render();
}

void PAT_Window::CleanRender()
{
	mRenderer.Clean();
}


void PAT_Window::AddToRender(PAT::Sprite* pSprite, SDL_Rect* pClip)
{
	mRenderer.AddToRender(pSprite, pClip);
//	if(SDL_RenderCopy( mRenderer, pSprite->mSprite, pClip, pClip) !=0)
//	{
//#ifdef DEBUG_MODE
//		std::cout << "Error SDL Renderer rendering: "
//			<< std::endl;
//		std::cout << SDL_GetError() << std::endl;
//#endif
//	}
}

void PAT_Window::DeleteSDLWindow()
{
	if(mWindow != nullptr)
	{
		SDL_DestroyWindow( mWindow );
	}
}

void PAT_Window::FreePixelFormat()
{
	if(mPixelFormat != nullptr)
	{
		SDL_FreeFormat(mPixelFormat);
	}
}
