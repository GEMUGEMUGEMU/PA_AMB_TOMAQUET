/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_EntityManager.cpp
*  Purpose:
*  Creation Date: 13-03-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "PAT_EntityManager.hpp"

namespace ECS
{


PAT_EntityManager::PAT_EntityManager()
{
	mEntityVector.reserve(NUM_INITIAL_ENTITIES);
}

EntityID PAT_EntityManager::CreateEntity()
{
	EntityID eid = ++mNextEntityID;
	mEntityVector.push_back(eid);
	return eid;
}

EntityID PAT_EntityManager::DeleteEntity(EntityID id)
{
	EntityID erased_id;

	for (auto it = mEntityVector.begin(); it != mEntityVector.end(); )
	{
        	if (*it == id)
		{
			erased_id = *it;
			it = mEntityVector.erase(it);
			return erased_id;
        	}
		else
		{
			++it;
        	}
    	}

	return 0;
}

Vector<EntityID>& PAT_EntityManager::GetEntities()
{
	return mEntityVector;
}

void PAT_EntityManager::DeleteEntityComponent(ComponentTypeID compTypeID,
	EntityID eID)
{
	mComponentStorage.DeleteEntityComponent(compTypeID, eID);
}


}
