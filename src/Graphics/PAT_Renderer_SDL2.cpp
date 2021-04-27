/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Renderer_SDL2.cpp
*  Purpose: Adapter of SDL2 renderer
*  Creation Date: 09-05-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "PAT_Renderer_SDL2.hpp"
#include "PAT_Sprite.hpp"

#ifdef DEBUG_MODE
#include <iostream>
#endif


namespace PAT
{
//SDL2 adapters names space
namespace SDL2A
{

RendererAdapter::RendererAdapter()
{
}

RendererAdapter::RendererAdapter(SDL_Renderer* pRenderer)
{
	if(pRenderer != nullptr)
	{
		mRenderer = pRenderer;
	}
}

RendererAdapter::RendererAdapter(RendererAdapter&& pAdapter)
  : mRenderer(pAdapter.mRenderer)
{
	pAdapter.mRenderer = nullptr;
}

RendererAdapter& RendererAdapter::operator=(RendererAdapter&& pAdapter)
{
	mRenderer = std::move(pAdapter.mRenderer);

	if(pAdapter.mRenderer != nullptr)
	{
		pAdapter.mRenderer = nullptr;
	}

	return *this;
}

RendererAdapter::~RendererAdapter()
{
	DeleteSDLRender();
}

void RendererAdapter::Render()
{
	SDL_RenderPresent( mRenderer );
}

void RendererAdapter::Clean()
{
	SDL_RenderClear( mRenderer );
}

void RendererAdapter::AddToRender(Sprite* pSprite, SDL_Rect* pClip)
{
	if(SDL_RenderCopy( mRenderer, pSprite->mSprite, pClip, pClip) !=0)
	{
#ifdef DEBUG_MODE
		std::cout << "Error SDL Renderer rendering: "
			<< std::endl;
		std::cout << SDL_GetError() << std::endl;
#endif
	}
}

void RendererAdapter::DeleteSDLRender()
{
	if(mRenderer != nullptr)
	{
		SDL_DestroyRenderer(mRenderer);
	}
}

}
}
