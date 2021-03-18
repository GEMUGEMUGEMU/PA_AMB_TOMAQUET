/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Test.cpp
*  Purpose:
*  Creation Date: 24-03-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "catch.hpp"
#include "PAT.hpp"

TEST_CASE("Initialize PAT use its methods and quit it", "[pat]")
{
	PAT::STATUS status = PAT::Init();

	WHEN("PAT is initialized")
	{

		THEN("can be initialized correctlyu")
		{
			REQUIRE(status == 0);
		}

		THEN("it's Component type ID doesn't change")
		{
			uint32_t ticks = PAT::GetTicks();
			REQUIRE(ticks != 0);
		}
	}

	PAT::Quit();
}
