/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: test2.cpp
*  Purpose:
*  Creation Date: 27-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "catch.hpp"

TEST_CASE( "Include various tests", "[dunno]" ) {
    REQUIRE( 1 == 1 );
    REQUIRE( 2 == 2 );
    REQUIRE( 3 == 6 );
    REQUIRE( 1 == 3628800 );
}
