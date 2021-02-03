/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: UpdateObject.h
*  Purpose: Wraps objects that can change over time
*  Creation Date: 27-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef UpdateObject_h
#define UpdateObject_h

class UpdateObject
{
public:
	UpdateObject(){}
	virtual ~UpdateObject(){}
//	Everything that needs to be update will be done here
	virtual void Update(float deltaTime) = 0;
};

#endif /* UpdateObject_h */
