/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: UpdateObject.h
*  Purpose:
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

	virtual void Update(float deltaTime){}
};

#endif /* UpdateObject_h */
