/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Renderer_SDL2.hpp
*  Purpose: Adapter of SDL2 renderer
*  Creation Date: 09-05-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Renderer_SDL2_hpp
#define PAT_Renderer_SDL2_hpp

#include "PAT_IRenderer.hpp"

namespace PAT
{
//SDL2 adapters names space
namespace SDL2A
{

struct RendererAdapter : public IRenderer
{
	RendererAdapter();
	RendererAdapter(SDL_Renderer* pRenderer);
	~RendererAdapter();

	RendererAdapter(RendererAdapter&& pAdapter);
	RendererAdapter& operator=( RendererAdapter&& pAdapter);

	RendererAdapter(const RendererAdapter&) = delete;

	void Render() override;
	void Clean() override;
	void AddToRender(Sprite* pSprite, Rect* pClip) override;


	SDL_Renderer* mRenderer {nullptr};

private:
	void DeleteSDLRender();
};

}
}
#endif /* PAT_Renderer_SDL2_hpp */
