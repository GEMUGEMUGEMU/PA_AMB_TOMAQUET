/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: T_PAT_Utils.cpp
*  Purpose:
*  Creation Date: 27-01-21
*  Created By: Andrea Andreu Salvagnin
*/
#include "PAT_Utils.h"

TEST_CASE( "PAT Utils tests pat_abs", "[dunno]" ) {
    REQUIRE( pat_abs(-1) == 1.0);
    REQUIRE( pat_abs(0) == 0.0 );
    REQUIRE( pat_abs(-1) != -1.0 );
    REQUIRE( pat_abs(-EPSILON) == EPSILON );
}

TEST_CASE( "PAT Utils tests f_equals", "[dunno]" ) {
    REQUIRE( f_equals(EPSILON, 0.0) == false);
    REQUIRE( f_equals(1.0 - EPSILON, 1.0) == false);
    REQUIRE( f_equals(-1.0, -1.0) == true);
    REQUIRE( f_equals(1.0, 1.0) == true);
    REQUIRE( f_equals(100, 1.0) == false);
}