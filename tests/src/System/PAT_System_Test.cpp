/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_System_Test.cpp
*  Purpose:
*  Creation Date: 24-03-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "catch.hpp"
#include "PAT_System.hpp"

TEST_CASE("Initialize PAT_System use its methods and quit it", "[pat]")
{
	PAT_System::STATUS status = PAT_System::Init();

	WHEN("PAT_System is initialized")
	{

		THEN("can be initialized correctlyu")
		{
			REQUIRE(status == 0);
		}

		THEN("it's Component type ID doesn't change")
		{
			uint32_t ticks = PAT_System::GetTicks();
			REQUIRE(ticks != 0);
		}
	}

	PAT_System::Quit();
}
