/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\ t  Gemu/~~
*
*  File Name: Vector2D.h
*  Purpose: 
*  Creation Date: 27-09-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Vector2D_h
#define Vector2D_h

class Vector2D
{
private:
	float mX, mY;
public:
	Vector2D(float x, float y): mX(x), mY(y){}
	Vector2D(): Vector2D(0, 0){}
	float ScalarProduct(const Vector2D& factorVector);
	float GetMagnitudePower2();
	float GetMagnitude();
	Vector2D& Normalize();

	Vector2D operator+(const Vector2D& sumVec) const;
	Vector2D operator*(float scalar) const;
	friend Vector2D operator*(float scalar, const Vector2D& vector);
	Vector2D operator/(float scalar) const;

	void SetX(float x){mX = x;}
	void SetY(float y){mY = y;}
	float GetX(){return mX;}
	float GetY(){return mY;}

};

#endif /* Vector2D_h */
