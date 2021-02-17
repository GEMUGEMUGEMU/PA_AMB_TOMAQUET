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

#include "PAT_GameObject.hpp"

class PAT_UpdateObject : public PAT_GameObject
{
public:
	PAT_UpdateObject();
	virtual ~PAT_UpdateObject();
//	Everything that could change as time passes will be done here
	virtual void Update(float deltaTime) = 0;
};

#endif /* PAT_UpdateObject_hpp */
