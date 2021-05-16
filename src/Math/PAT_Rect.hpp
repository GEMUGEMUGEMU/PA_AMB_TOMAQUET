/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Rect.hpp
*  Purpose:
*  Creation Date: 14-05-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Rect_hpp
#define PAT_Rect_hpp
#include <SDL2/SDL.h>

namespace PAT
{
namespace SDLA
{

struct Rect
{
	Rect(int x, int y, int w, int h);
	Rect();

	SDL_Rect mRectancle;
};

}
}
#endif /* PAT_Rect_hpp */
