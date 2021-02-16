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
	PAT_GameObject* removeObject = nullptr;

	do
	{
		removeObject = mGraphicObjectsList.RemoveAtIndex(0);
		if(removeObject)
		{
			RemoveFromLists(removeObject);
			delete removeObject;
		}
	}
	while(removeObject != nullptr);

	do
	{
		removeObject = mUpdateObjectsList.RemoveAtIndex(0);
		if(removeObject)
		{
			RemoveFromLists(removeObject);
			delete removeObject;
		}
	}
	while(removeObject != nullptr);

	do
	{
		removeObject = mCollObjList.RemoveAtIndex(0);
		if(removeObject)
		{
			RemoveFromLists(removeObject);
			delete removeObject;
		}
	}
	while(removeObject != nullptr);
}

void PAT_GameObjectsManager::Update(float deltaTime)
{
	uint32_t max = mUpdateObjectsList.GetSize();
	PAT_UpdateObject* tObject;

	uint32_t counter = 0;

	while ( counter < max)
	{
		tObject = mUpdateObjectsList.Get(counter);
		tObject->Update(deltaTime);
		counter = counter + 1;
	}
}

void PAT_GameObjectsManager::Draw(SDL_Renderer * render)
{
	uint32_t max = mGraphicObjectsList.GetSize();
	PAT_GraphicObject* drawObject;

	uint32_t counter = 0;

	while ( counter < max)
	{
		drawObject = mGraphicObjectsList.Get(counter);
		drawObject->Draw(render);
		counter = counter + 1;
	}
}

void PAT_GameObjectsManager::Input(SDL_Event * event)
{
	if(mController)
	{
		mController->Input(event);
	}
}

void PAT_GameObjectsManager::AddCollidingObj(PAT_CollidingObject* newObject)
{
	mCollObjList.Add(newObject);
}

void PAT_GameObjectsManager::AddGrpahicObj(PAT_GraphicObject* newObject)
{

	mGraphicObjectsList.Add(newObject);
}

void PAT_GameObjectsManager::AddUpdateObj(PAT_UpdateObject* newObject)
{

	mUpdateObjectsList.Add(newObject);
}

void PAT_GameObjectsManager::RemoveFromLists(PAT_GameObject* gameObject)
{
	PAT_CollidingObject* collObj =
		dynamic_cast<PAT_CollidingObject*>(gameObject);
	if(collObj)
	{
		mCollObjList.Remove(collObj);
	}


	PAT_GraphicObject* graphObj =
		dynamic_cast<PAT_GraphicObject*>(gameObject);
	if(graphObj)
	{
		mGraphicObjectsList.Remove(graphObj);
	}


	PAT_UpdateObject* upObj =
		dynamic_cast<PAT_UpdateObject*>(gameObject);
	if(upObj)
	{
		mUpdateObjectsList.Remove(upObj);
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


void PAT_GameObjectsManager::RemoveGameObject(PAT_GameObject* gameObject)
{
	RemoveFromLists(gameObject);

	delete(gameObject);
}
