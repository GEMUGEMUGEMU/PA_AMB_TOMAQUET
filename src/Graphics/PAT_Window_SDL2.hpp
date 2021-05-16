/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Window_SDL2.hpp
*  Purpose:
*  Creation Date: 14-05-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Window_SDL2_hpp
#define PAT_Window_SDL2_hpp

#include <SDL2/SDL.h>
#include "PAT_IWindow.hpp"

namespace PAT
{
namespace SDL2A
{

struct WindowAdapter : IWindow
{
	typedef short unsigned int SI;
	WindowAdapter();
	~WindowAdapter();

	Status InitRenderer(Renderer& pRenderer) override;

	Status Init(SI height, SI width, const char* windowName);

private:
	void DeleteSDLWindow();
	void FreePixelFormat();


	SDL_Window* mWindow { nullptr };
	SDL_PixelFormat* mPixelFormat { nullptr };
	uint32_t mCleanColor;
};

}
}
#endif /* PAT_Window_SDL2_hpp */
