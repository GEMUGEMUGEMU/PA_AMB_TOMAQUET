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