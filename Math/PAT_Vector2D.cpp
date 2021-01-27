/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\ t  Gemu/~~
*
*  File Name: PAT_Vector2D.cpp
*  Purpose:
*  Creation Date: 27-09-20
*  Created By: Andrea Andreu Salvagnin
*/
#include "PAT_Vector2D.h"
#include "PAT_Utils.h"
#include <cmath>

const PAT_Vector2D PAT_Vector2D::vector2DZero;

float PAT_Vector2D::ScalarProduct(const PAT_Vector2D& factorVector)
{
	return mX * factorVector.mX + mY * factorVector.mY;
}

float PAT_Vector2D::GetMagnitudePower2()
{
	return ScalarProduct(*this);
}

float PAT_Vector2D::GetMagnitude()
{
	return sqrtf(GetMagnitudePower2());
}

PAT_Vector2D& PAT_Vector2D::Normalize()
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

PAT_Vector2D PAT_Vector2D::operator+(const PAT_Vector2D& sumVec) const
{
	return PAT_Vector2D(mX + sumVec.mX, mY + sumVec.mY);
}

PAT_Vector2D PAT_Vector2D::operator*(float scalar) const
{
	return PAT_Vector2D(mX * scalar, mY * scalar);
}

PAT_Vector2D operator*(float scalar, PAT_Vector2D vector)
{
	return vector * scalar;
}

PAT_Vector2D PAT_Vector2D::operator/(float scalar) const
{
	if( fabsf(scalar) > 0.0001f)
	{
		return PAT_Vector2D(mX / scalar, mY / scalar);
	}
	else
	{
		return PAT_Vector2D();
	}
}

bool PAT_Vector2D::operator==(const PAT_Vector2D& vector2D) const
{
	return FloatIsEquals(mX, vector2D.mX)
		&& FloatIsEquals(mY, vector2D.mY);
}

