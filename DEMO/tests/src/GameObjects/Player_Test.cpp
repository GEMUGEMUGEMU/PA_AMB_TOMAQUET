/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: Player_Test.cpp
*  Purpose:
*  Creation Date: 16-02-21
*  Created By: Andrea Andreu Salvagnin
*/
#include "catch.hpp"
#include "Player.hpp"

TEST_CASE("Instantiate player") {
	Player player();
	REQUIRE(true);
}

