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
#include "PAT_Vector2D.hpp"
#include "PAT_MathUtils.hpp"
#include <cmath>

const PAT_Vector2D PAT_Vector2D::Vector2DZero(0, 0);

float PAT_Vector2D::ScalarProduct(const PAT_Vector2D& rFactorVector)
{
	return mX * rFactorVector.mX + mY * rFactorVector.mY;
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

PAT_Vector2D PAT_Vector2D::operator+(const PAT_Vector2D& rSumVec) const
{
	return PAT_Vector2D(mX + rSumVec.mX, mY + rSumVec.mY);
}

PAT_Vector2D PAT_Vector2D::operator*(float pScalar) const
{
	return PAT_Vector2D(mX * pScalar, mY * pScalar);
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
		return PAT_Vector2D(0, 0);
	}
}

bool PAT_Vector2D::operator==(const PAT_Vector2D& rVector2D) const
{
	return FloatIsEquals(mX, rVector2D.mX)
		&& FloatIsEquals(mY, rVector2D.mY);
}

bool PAT_Vector2D::EqualsVectorZero()
{
	return *this == Vector2DZero;
}


PAT_Vector2D& PAT_Vector2D::operator=(const PAT_Vector2D& rVector)
{
	mX = rVector.mX;
	mY = rVector.mY;

	return *this;
}

PAT_Vector2D& PAT_Vector2D::operator=(const PAT_Vector2D* pVector)
{
	mX = pVector->mX;
	mY = pVector->mY;

	return *this;
}

float PAT_Vector2D::DistanceFromPoint(const PAT_Vector2D& rVec)
{

	return GetHypotenuse( rVec.mX - this->mX, rVec.mY - this->mY );
}

float PAT_Vector2D::DistanceFromPoint(const PAT_Vector2D* pVec)
{

	return GetHypotenuse( pVec->mX - this->mX, pVec->mY - this->mY );
}
