/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Rect.cpp
*  Purpose:
*  Creation Date: 14-05-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "PAT_Rect.hpp"

namespace PAT
{
namespace SDLA
{

Rect::Rect(int x, int y, int w, int h)
{
	mRectancle.x = x;
	mRectancle.y = y;
	mRectancle.w = w;
	mRectancle.h = h;
}

Rect::Rect() : Rect(0, 0, 0, 0)
{

}

}
}
