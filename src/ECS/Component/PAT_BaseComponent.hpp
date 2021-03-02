/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_BaseComponent.hpp
*  Purpose:
*  Creation Date: 24-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_BaseComponent_hpp
#define PAT_BaseComponent_hpp

#include "PAT_Component.hpp"

namespace ECS
{

template<typename TypeComponent>
struct PAT_BaseComponent : PAT_Component
{
	explicit PAT_BaseComponent(EntityID eid) : PAT_Component(eid) {}

	static ComponentTypeID GetComponetTypeID() noexcept
	{
		static ComponentTypeID type_id { ++mNextTypeID };
		return type_id;
	}
};

}
#endif /* PAT_BaseComponent_hpp */
