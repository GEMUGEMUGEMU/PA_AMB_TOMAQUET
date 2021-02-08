/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PAT_UpdateObject.h
*  Purpose: Wraps objects that can change over time
*  Creation Date: 27-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_UpdateObject_hpp
#define PAT_UpdateObject_hpp

class PAT_UpdateObject
{
public:
	PAT_UpdateObject(){}
	virtual ~PAT_UpdateObject(){}
//	Everything that needs to be update will be done here
	virtual void Update(float deltaTime) = 0;
};

#endif /* PAT_UpdateObject_hpp */
