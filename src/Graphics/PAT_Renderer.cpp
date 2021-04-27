/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Renderer.cpp
*  Purpose:
*  Creation Date: 09-05-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "PAT_Renderer.hpp"


namespace PAT
{

using namespace SDL2A;

Renderer::Renderer()
{

}

Renderer::Renderer(RendererAdapter& pAdapter)
{
	mAdapter = std::move(pAdapter);
//	mAdapter(&pAdapter);
//	mAdapter = pAdapter.MoveRenderer();
}

Renderer::~Renderer()
{
//	mAdapter.Delete();
}

void Renderer::Render()
{
	mAdapter.Render();
}

void Renderer::Clean()
{
	mAdapter.Clean();
}

void Renderer::AddToRender(Sprite* pSprite, SDL_Rect* pClip)
{
	mAdapter.AddToRender(pSprite, pClip);
}

Renderer::Renderer(Renderer&& pRenderer)
{
	mAdapter = std::move(pRenderer.mAdapter);
}

Renderer& Renderer::operator=(Renderer&& pRenderer)
{
	mAdapter = std::move(pRenderer.mAdapter);

	return *this;
}



}
