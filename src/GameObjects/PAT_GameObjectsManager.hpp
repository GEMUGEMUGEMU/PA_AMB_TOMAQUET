/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_GameObjectsManager.hpp
*  Purpose:
*  Creation Date: 13-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_GameObjectsManager_hpp
#define PAT_GameObjectsManager_hpp

#include "PAT_CollidingObject.hpp"
#include "PAT_LinkedList.hpp"
#include "PAT_GraphicObject.hpp"
#include "PAT_UpdateObject.hpp"
#include "PAT_Controller.hpp"

class PAT_GameObjectsManager
{
public:
	PAT_GameObjectsManager();
	~PAT_GameObjectsManager();

	virtual void Init(SDL_Renderer * renderer) = 0;

	void Update(float deltaTime);
	void Draw(SDL_Renderer * renderer);
	void Input(SDL_Event * event);
	void CheckCollisions();

protected:
	void AddCollidingObj(PAT_CollidingObject* newObject);
	void AddGrpahicObj(PAT_GraphicObject* newObject);
	void AddUpdateObj(PAT_UpdateObject* newObject);
	void RemoveFromLists(PAT_GameObject* gameObject);
	void RemoveGameObject(PAT_GameObject* gameObject);
	PAT_Controller* mController;

private:

	PAT_LinkedList<PAT_CollidingObject> mCollObjList;
	PAT_LinkedList<PAT_GraphicObject> mGraphicObjectsList;
	PAT_LinkedList<PAT_UpdateObject> mUpdateObjectsList;
};

#endif /* PAT_GameObjectsManager_hpp */
