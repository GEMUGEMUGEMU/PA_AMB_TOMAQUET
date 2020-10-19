/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\ t  Gemu/~~
*
*  File Name: Vector2D.cpp
*  Purpose: 
*  Creation Date: 27-09-20
*  Created By: Andrea Andreu Salvagnin
*/
#include "Vector2D.h"
#include <cmath>


float Vector2D::ScalarProduct(const Vector2D& factorVector)
{
	return mX * factorVector.mX + mY * factorVector.mY;	
}

float Vector2D::GetMagnitudePower2()
{
	return ScalarProduct(*this);
}

float Vector2D::GetMagnitude()
{
	return sqrtf(GetMagnitudePower2());
}

Vector2D& Vector2D::Normalize()
{
	float magnitude = GetMagnitude();
	if( magnitude > 0.0001f)
	{
		return *this = *this / magnitude;
	}
	else
	{
		return *this;
	}
}

Vector2D Vector2D::operator+(const Vector2D& sumVec) const
{
	return Vector2D(mX + sumVec.mX, mY + sumVec.mY);
}

Vector2D Vector2D::operator*(float scalar) const
{
	return Vector2D(mX * scalar, mY * scalar);
}

Vector2D operator*(float scalar, Vector2D vector)
{
	return vector * scalar;
}

Vector2D Vector2D::operator/(float scalar) const
{
	if( fabsf(scalar) > 0.0001f)
	{
		return Vector2D(mX / scalar, mY / scalar);
	}
	else
	{
		return Vector2D();
	}
}
