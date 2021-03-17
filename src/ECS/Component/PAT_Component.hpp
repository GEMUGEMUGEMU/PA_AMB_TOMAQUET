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

struct PAT_BaseComponent
{
	EntityID GetEnityID()
	{
		return mEntityID;
	}

protected:
	explicit PAT_BaseComponent(EntityID entityID) : mEntityID(entityID){ }
	static inline ComponentTypeID mNextTypeID { 0 };

private:
	EntityID mEntityID { 0 };
};

template<typename TypeComponent>
struct PAT_Component : PAT_BaseComponent
{
	explicit PAT_Component(EntityID eid) : PAT_BaseComponent(eid) {}

	static ComponentTypeID GetComponentTypeID() noexcept
	{
		static ComponentTypeID type_id { ++mNextTypeID };
		return type_id;
	}
};

}
#endif /* PAT_Component_hpp */
