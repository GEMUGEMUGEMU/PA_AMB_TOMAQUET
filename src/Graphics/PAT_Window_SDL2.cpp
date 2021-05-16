/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Window_SDL2.cpp
*  Purpose:
*  Creation Date: 14-05-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "PAT_Window_SDL2.hpp"
#include "PAT_System.hpp"

namespace PAT
{
namespace SDL2A
{

WindowAdapter::WindowAdapter()
{
}

WindowAdapter::~WindowAdapter()
{
	DeleteSDLWindow();
	FreePixelFormat();
}

Status WindowAdapter::InitRenderer(Renderer& pRenderer)
{
	if(PAT_System::WasInit() != 0)
	{
		return Status::PAT_SYS_UNINT;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(mWindow, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if(renderer == nullptr)
	{
#ifdef DEBUG_MODE
		std::cout << "Error SDL Renderer initialization: "
			<< std::endl;
		std::cout << SDL_GetError() << std::endl;
#endif

		return Status::INIT_ERROR;
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255 );

	PAT::SDL2A::RendererAdapter renderer_adapter(renderer);

	pRenderer = PAT::Renderer(renderer_adapter);

	return Status::OK;
}

Status WindowAdapter::Init(SI pHeight, SI pWidth, const char* pWindowName)
{
	if(PAT_System::WasInit() != 0)
	{
		return Status::PAT_SYS_UNINT;
	}

	if( pWidth == 0 or pHeight == 0 or pWindowName == nullptr)
	{
		return Status::INVALID_ARGS;
	}

	mWindow = SDL_CreateWindow( pWindowName, SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, pWidth, pHeight, /*SDL_WINDOW_SHOWN*/
		SDL_WINDOW_MAXIMIZED);

	if(mWindow == nullptr)
	{
#ifdef DEBUG_MODE
		std::cout << "Error SDL Window initialization: "
			<< std::endl;
		std::cout << SDL_GetError() << std::endl;
#endif

		return Status::INIT_ERROR;
	}

	mPixelFormat =
		SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);

	mCleanColor = SDL_MapRGBA( mPixelFormat, 0, 0, 255, 255);

	return Status::OK;
}

void WindowAdapter::DeleteSDLWindow()
{
	if(mWindow != nullptr)
	{
		SDL_DestroyWindow( mWindow );
	}
}

void WindowAdapter::FreePixelFormat()
{
	if(mPixelFormat != nullptr)
	{
		SDL_FreeFormat(mPixelFormat);
	}
}

}
}
