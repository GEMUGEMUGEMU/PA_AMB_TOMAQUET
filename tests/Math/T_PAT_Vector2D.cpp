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


TEST_CASE( "Test PAT_Vector2D equals") {
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
	PAT_Vector2D* vector3 = new PAT_Vector2D(3,6);

	vector1 = vector2;
	REQUIRE((vector1.GetX()==vector2.GetX()) ==
			(vector1.GetY()==vector2.GetY()));

	vector1 = vector3;
	REQUIRE((vector1.GetX()==vector3->GetX()) ==
			(vector1.GetY()==vector3->GetY()));

}

