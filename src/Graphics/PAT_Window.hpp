/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Window.hpp
*  Purpose: SDL_Window Adapter
*  Creation Date: 23-03-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Window_hpp
#define PAT_Window_hpp

#include "PAT_IWindow.hpp"
#include "PAT_Window_SDL2.hpp"

namespace PAT
{
using namespace SDL2A;

struct Window : public IWindow
{
	typedef short unsigned int SI;

	Window();
	~Window();

	Status InitRenderer(Renderer& pRenderer) override;

	Status Init(SI height, SI width, const char* windowName);

	WindowAdapter mAdapter;
};

}
#endif /* PAT_Window_hpp */
