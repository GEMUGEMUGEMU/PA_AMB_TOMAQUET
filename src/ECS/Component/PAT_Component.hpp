/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Component.hpp
*  Purpose:
*  Creation Date: 24-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Component_hpp
#define PAT_Component_hpp

#include "PAT_ECSAlias.hpp"

namespace ECS
{

struct PAT_Component
{

protected:
	explicit PAT_Component(EntityID entityID);
	static ComponentTypeID mNextTypeID;

private:
	EntityID mEntityID { 0 };
};

}
#endif /* PAT_Component_hpp */
