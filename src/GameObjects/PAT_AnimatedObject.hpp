/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_AnimatedObject.hpp
*  Purpose: Everithing that isn''t static and drawable is an
*           animated object.
*  Creation Date: 12-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_AnimatedObject_hpp
#define PAT_AnimatedObject_hpp

#include "PAT_Vector2D.hpp"
#include "PAT_UpdateObject.hpp"
#include "PAT_GraphicObject.hpp"

class PAT_AnimatedObject : public PAT_GraphicObject, public PAT_UpdateObject
{
public:
	PAT_AnimatedObject();
	virtual ~PAT_AnimatedObject();
};

#endif /* PAT_AnimatedObject_hpp */
