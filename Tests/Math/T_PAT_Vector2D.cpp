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
	PAT_Vector2D testZero1;

	REQUIRE((testVector == PAT_Vector2D::Vector2DZero)
			== false);
	REQUIRE((testZero == PAT_Vector2D::Vector2DZero)
			== true);
	REQUIRE((testZero1 == PAT_Vector2D::Vector2DZero)
			== true);
}


TEST_CASE( "Test PAT_Vector2D assignation") {
	PAT_Vector2D vector1(1,1);
	PAT_Vector2D vector2(7,9);

	vector1 = vector2;
	REQUIRE((vector1.GetX()==vector1.GetX()) ==
			(vector1.GetY()==vector1.GetY()));
}
