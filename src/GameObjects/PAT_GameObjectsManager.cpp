/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_GameObjectsManager.cpp
*  Purpose:
*  Creation Date: 13-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "PAT_GameObjectsManager.hpp"

PAT_GameObjectsManager::PAT_GameObjectsManager()
{
}

PAT_GameObjectsManager::~PAT_GameObjectsManager()
{
	PAT_GameObject* remove_object = nullptr;

	do
	{
		remove_object = mGraphicObjectsList.RemoveAtIndex(0);
		if(remove_object)
		{
			RemoveFromLists(remove_object);
			delete remove_object;
		}
	}
	while(remove_object != nullptr);

	do
	{
		remove_object = mUpdateObjectsList.RemoveAtIndex(0);
		if(remove_object)
		{
			RemoveFromLists(remove_object);
			delete remove_object;
		}
	}
	while(remove_object != nullptr);

	do
	{
		remove_object = mCollObjList.RemoveAtIndex(0);
		if(remove_object)
		{
			RemoveFromLists(remove_object);
			delete remove_object;
		}
	}
	while(remove_object != nullptr);
}

void PAT_GameObjectsManager::Update(float deltaTime)
{
	uint32_t max = mUpdateObjectsList.GetSize();
	PAT_UpdateObject* update_object;

	uint32_t counter = 0;

	while ( counter < max)
	{
		update_object = mUpdateObjectsList.Get(counter);
		update_object->Update(deltaTime);
		counter = counter + 1;
	}
}

void PAT_GameObjectsManager::Draw(SDL_Renderer * pRenderer)
{
	uint32_t max = mGraphicObjectsList.GetSize();
	PAT_GraphicObject* draw_object;

	uint32_t counter = 0;

	while ( counter < max)
	{
		draw_object = mGraphicObjectsList.Get(counter);
		draw_object->Draw(pRenderer);
		counter = counter + 1;
	}
}

void PAT_GameObjectsManager::Input(SDL_Event * pEvent)
{
	if(mController)
	{
		mController->Input(pEvent);
	}
}

void PAT_GameObjectsManager::AddCollidingObj(PAT_CollidingObject* pNewObject)
{
	mCollObjList.Add(pNewObject);
}

void PAT_GameObjectsManager::AddGrpahicObj(PAT_GraphicObject* pNewObject)
{

	mGraphicObjectsList.Add(pNewObject);
}

void PAT_GameObjectsManager::AddUpdateObj(PAT_UpdateObject* pNewObject)
{

	mUpdateObjectsList.Add(pNewObject);
}

void PAT_GameObjectsManager::RemoveFromLists(PAT_GameObject* gameObject)
{
	PAT_CollidingObject* coll_obj =
		dynamic_cast<PAT_CollidingObject*>(gameObject);
	if(coll_obj)
	{
		mCollObjList.Remove(coll_obj);
	}


	PAT_GraphicObject* graph_obj =
		dynamic_cast<PAT_GraphicObject*>(gameObject);
	if(graph_obj)
	{
		mGraphicObjectsList.Remove(graph_obj);
	}


	PAT_UpdateObject* update_obj =
		dynamic_cast<PAT_UpdateObject*>(gameObject);
	if(update_obj)
	{
		mUpdateObjectsList.Remove(update_obj);
	}

	PAT_Controller* controller =
		dynamic_cast<PAT_Controller*>(gameObject);
	if(controller == mController)
	{
		mController = nullptr;
	}
}

void PAT_GameObjectsManager::CheckCollisions()
{
	uint32_t max = mCollObjList.GetSize();

	if( max > 0)
	{
		uint32_t counter = 0;
		uint32_t iterationCounter = 0;

		PAT_CollidingObject* collided = nullptr;
		PAT_CollidingObject* colliding = nullptr;
		while ( counter < max)
		{
			collided = mCollObjList.Get(counter);

			while (iterationCounter < max)
			{
				if(iterationCounter != counter)
				{
					colliding =
						mCollObjList.Get(
								iterationCounter);

					collided->HasCollidedWith(
							colliding->GetHitbox());
				}

				iterationCounter = iterationCounter + 1;
			}

			counter = counter + 1;
		}

		counter = 0;

		while ( max > 0 && counter < max)
		{
			collided = mCollObjList.Get(counter);

			if(collided->mHasCollided)
			{
				RemoveGameObject(collided);
				max = mCollObjList.GetSize();
			}

			counter = counter + 1;
		}
	}
}


void PAT_GameObjectsManager::RemoveGameObject(PAT_GameObject* pGameObject)
{
	RemoveFromLists(pGameObject);

	delete(pGameObject);
}
