/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Utils.cpp
*  Purpose:
*  Creation Date: 27-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "PAT_MathUtils.h"
#include <cmath>

float pat_abs(float n1)
{
	if( n1 < 0.0)
	{
		return n1 * (-1.0);
	}
	else
	{
		return n1;
	}
}


bool FloatIsEquals(float n1, float n2)
{

	if(pat_abs(n1 - n2) < EPSILON)
	{
		return true;
	}
	else
	{
		return false;
	}
}

float GetHypotenuse(float leg1, float leg2)
{
	return sqrtf( pow( leg1, 2) + pow( leg2, 2) );
}

float TwoPointsDistance(Vector2D v1, Vector2D v2)
{
	return GetHypotenuse( v2.GetX() - v1.GetX(), v2.GetY() - v1.GetY() );
}


