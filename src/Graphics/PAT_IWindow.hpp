/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_IWindow.hpp
*  Purpose: Interface for Window
*  Creation Date: 14-05-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_IWindow_hpp
#define PAT_IWindow_hpp

#include "PAT_Sprite.hpp"
#include "PAT_Renderer.hpp"
#include "PAT_Status.hpp"

namespace PAT
{

struct IWindow
{
	typedef short unsigned int SI;

	~IWindow() = default;

	virtual Status InitRenderer(Renderer& pRenderer) = 0;
};

}
#endif /* PAT_IWindow_hpp */
