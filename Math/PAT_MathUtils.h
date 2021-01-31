/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_MathUtils.h
*  Purpose:
*  Creation Date: 27-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_MAthUtils_h
#define PAT_MAthUtils_h

static const float EPSILON = 0.0001f;

float pat_abs(float n1);

bool FloatIsEquals(float n1, float n2);
//Pythagorean theorem
float GetHypotenuse(float leg1, float leg2);

float TwoPointsDistance(Vector2D v1, Vector2D v2);

#endif /* PAT_MAthUtils_h */
