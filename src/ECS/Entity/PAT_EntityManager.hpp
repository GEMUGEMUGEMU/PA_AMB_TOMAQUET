/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_EntityManager.hpp
*  Purpose:
*  Creation Date: 13-03-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_EntityManager_hpp
#define PAT_EntityManager_hpp

#include "PAT_GameContext.hpp"
#include "PAT_ECSAlias.hpp"
#include "PAT_ComponentStorage.hpp"


namespace ECS
{

struct PAT_EntityManager : public PAT_GameContext
{
	explicit PAT_EntityManager();

	EntityID CreateEntity();
	EntityID DeleteEntity(EntityID id);

	VecEntities& GetEntities();

	template<typename ComponentType>
	ComponentType& CreateComponent(EntityID id)
	{
		return mComponentStorage.CreateComponent<ComponentType>(id);
	}

	void DeleteEntityComponent(ComponentTypeID compTypeID, EntityID eID);

	//Vector<EntityID> mEntityVector;
	VecEntities mEntityVector;

private:
	static inline std::size_t NUM_INITIAL_ENTITIES {100};
	inline static EntityID mNextEntityID { 0 };
	PAT_ComponentStorage mComponentStorage { NUM_INITIAL_ENTITIES };

};

}

#endif /* PAT_EntityManager_hpp */
