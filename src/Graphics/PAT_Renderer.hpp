/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Renderer.hpp
*  Purpose:
*  Creation Date: 09-05-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Renderer_hpp
#define PAT_Renderer_hpp

#include "PAT_IRenderer.hpp"
#include "PAT_Renderer_SDL2.hpp"

namespace PAT
{

using namespace SDL2A;

struct Renderer : public IRenderer
{
	Renderer();
	Renderer(RendererAdapter& pAdapter);
	~Renderer();

	void Render() override;
	void Clean() override;
	void AddToRender(Sprite* pSprite, SDL_Rect* pClip)  override;

	Renderer(Renderer&& pRenderer);
	Renderer& operator=(Renderer&& pRenderer);


//protected:
	//SDL2 adapter
	RendererAdapter mAdapter;
};

}
#endif /* PAT_Renderer_hpp */


