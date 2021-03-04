/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Entity.hpp
*  Purpose:
*  Creation Date: 24-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Entity_hpp
#define PAT_Entity_hpp

#include "PAT_ECSAlias.hpp"
#include "PAT_Component.hpp"

namespace ECS{

struct PAT_Entity
{
	template<typename ComponentType>
	static ComponentTypeID GetComponentTypeID()
	{
		static ComponentTypeID type {++mNextTypeID};
		return type;
	}

	template<typename ComponentType>
	void AddComponent(ComponentType& rComp)
	{
		auto type = GetComponentTypeID<ComponentType>();
		mComponentsMap[type] = &rComp;
	}

	template<typename ComponentType>
	ComponentType* GetComponent()
	{
		auto type = GetComponentTypeID<ComponentType>();
		auto iterator = mComponentsMap.find(type);
		if( iterator != mComponentsMap.end() )
		{
			return static_cast<ComponentType*>(iterator->second);
		}
		return nullptr;
	}

	template<typename ComponentType>
	const ComponentType* GetComponent()
	{
		//Call non const function
		auto p_component = const_cast<PAT_Entity*>
			(this)->GetComponent<ComponentType>();
		//Cast const and return
		return const_cast<const ComponentType*>(p_component);
	}

protected:
	static EntityID mNextEntityID;
	static ComponentTypeID mNextTypeID;
	std::unordered_map<ComponentID, PAT_Component> mComponentsMap;
};

}
#endif /* PAT_Entity_hpp */
