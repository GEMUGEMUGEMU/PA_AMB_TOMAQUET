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
#include "TestWindow.hpp"
#include "PAT_System.hpp"

TEST_CASE("Instantiate a PAT window", "[grphcs]")
{
	TestWindow t_window;

	WHEN("a pat window is instantiated without PAT been initialized")
	{
		PAT_System::Quit();
		THEN("initializing a PAT window retunrs an error")
		{
			REQUIRE(t_window.TestInit() != 0);
		}

		PAT_System::Init();
		THEN("initializing PAT then initializing a PAT window")
		{
			REQUIRE(t_window.TestInit() == 0);
		}
		PAT_System::Quit();
	}
}

