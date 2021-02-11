/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\ t  Gemu/~~
*
*  File Name: PAT_Vector2D.hpp
*  Purpose:
*  Creation Date: 27-09-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Vector2D_hpp
#define PAT_Vector2D_hpp

class PAT_Vector2D
{
private:
	float mX, mY;
public:
	PAT_Vector2D(float x, float y): mX(x), mY(y){}
	PAT_Vector2D(): PAT_Vector2D(0, 0){}
	PAT_Vector2D(const PAT_Vector2D& vector)
		: mX(vector.mX), mY(vector.mY) {}

	float ScalarProduct(const PAT_Vector2D& factorVector);
	float GetMagnitudePower2();
	float GetMagnitude();
	float DistanceFromPoint(const PAT_Vector2D& vec);
	float DistanceFromPoint(const PAT_Vector2D* vec);
	PAT_Vector2D& Normalize();

	PAT_Vector2D& operator=(const PAT_Vector2D& vec);
	PAT_Vector2D& operator=(const PAT_Vector2D* vec);

	PAT_Vector2D operator+(const PAT_Vector2D& sumVec) const;
	PAT_Vector2D operator*(float scalar) const;
	friend PAT_Vector2D operator*(float scalar, const PAT_Vector2D& vector);
	PAT_Vector2D operator/(float scalar) const;

	bool operator==(const PAT_Vector2D& vector2D) const;

	void SetX(float x){mX = x;}
	void SetY(float y){mY = y;}
	float GetX(){return mX;}
	float GetY(){return mY;}

	bool EqualsVectorZero();

	static const PAT_Vector2D Vector2DZero;
};

#endif /* PAT_Vector2D_hpp */
