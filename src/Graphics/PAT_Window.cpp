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

namespace PAT
{

Window::Window()
{
}

Window::~Window()
{
}

Status Window::InitRenderer(Renderer& pRenderer)
{
	return mAdapter.InitRenderer(pRenderer);
}

Status Window::Init(SI height, SI width, const char* windowName)
{
	return mAdapter.Init(height, width, windowName);
}

}

