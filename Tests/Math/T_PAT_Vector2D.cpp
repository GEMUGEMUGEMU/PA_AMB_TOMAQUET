/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: T_PAT_Vector2D.cpp
*  Purpose:
*  Creation Date: 27-01-21
*  Created By: Andrea Andreu Salvagnin
*/
#include "PAT_Vector2D.h"


TEST_CASE( "Test PAT_Vector2D ") {
	PAT_Vector2D testVector(0,1);
	PAT_Vector2D testZero(0,0);

	REQUIRE(
		(testVector == PAT_Vector2D::Vector2DZero)
			 == false);
	REQUIRE(
		(testZero == PAT_Vector2D::Vector2DZero)
			 == true);

}
