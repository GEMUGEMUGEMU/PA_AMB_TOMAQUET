/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: TestWindow.hpp
*  Purpose:
*  Creation Date: 04-05-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef TestWindow_hpp
#define TestWindow_hpp


#include "PAT_Window.hpp"

struct TestWindow : public PAT_Window
{
	TestWindow() : PAT_Window(100, 100, "Test window") { }
};

#endif /* TestWindow_hpp */
