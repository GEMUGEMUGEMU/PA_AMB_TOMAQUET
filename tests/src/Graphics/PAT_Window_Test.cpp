/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Window_Test.cpp
*  Purpose:
*  Creation Date: 26-03-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "catch.hpp"
#include "PAT_Window.hpp"

TEST_CASE("Instantiate a PAT window", "[grphcs]")
{
	struct TestWindow : public PAT_Window
	{
		TestWindow() : PAT_Window(100, 100, "Test window") { }
	};

	TestWindow t_window;

	WHEN("a pat window is instantiated without PAT been initialized")
	{
		PAT_System::Quit();
		THEN("initializing a PAT window retunrs an error")
		{
			REQUIRE(t_window.Init() != 0);
		}

		PAT_System::Init();
		THEN("initializing PAT then initializing a PAT window")
		{
			REQUIRE(t_window.Init() == 0);
		}
		PAT_System::Quit();
	}

//	WHEN("it's added a render to window renderer")
//	{
//		PAT::Init();
//
//		THEN("It's possible to add the render")
//		{
//			REQUIRE(t_window.AddToRender(PAT_Sprite* pSprite) == 0);
//		}
//		PAT::Quit();
//	}
}

