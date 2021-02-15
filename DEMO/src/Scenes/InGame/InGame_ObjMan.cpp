/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: InGame_ObjMan.cpp
*  Purpose:
*  Creation Date: 14-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#include"PAT_GameObject.hpp"
#include "InGame_ObjMan.hpp"
#include "Player.hpp"
#include "NPC.hpp"
#include "Instructions.hpp"
#include "InGameTitle.hpp"

InGame_ObjMan::InGame_ObjMan()
{
}

InGame_ObjMan::~InGame_ObjMan()
{
	PAT_GameObject* deleteGameObject = nullptr;
	PAT_Subject* deleteSubject = nullptr;

	do
	{
		deleteGameObject = nullptr;
		deleteSubject = nullptr;

		deleteSubject = mSubjectlist.RemoveAtIndex(0);

		if(deleteSubject)
		{
			//Check if it's a game object
			deleteGameObject =
				dynamic_cast<PAT_GameObject*>(deleteSubject);
			if(deleteGameObject)
			{
				RemoveFromLists(deleteGameObject);
			}

			delete deleteSubject;
		}
	}
	while(deleteSubject != nullptr);
}

void InGame_ObjMan::Init(SDL_Renderer * renderer)
{
	Player * player = new Player();
	player->Init(32, PAT_Vector2D(10, 100), renderer);

	AddGrpahicObj(player);
	AddUpdateObj(player);
	AddCollidingObj(player);
	mSubjectlist.Add(player);

	player->Attach(this);

	mController = player;

	NPC* npc = new NPC();
	npc->Init(PAT_Vector2D(15, 100), renderer);
	AddGrpahicObj(npc);
	AddUpdateObj(npc);
	AddCollidingObj(npc);
	mSubjectlist.Add(npc);

	npc->Attach(this);

	InGameTitle* title = new InGameTitle();
	title->Init(10, 10, renderer);
	AddGrpahicObj(title);

	Instructions* instr = new Instructions();
	instr->Init(10, 350, renderer);

	AddGrpahicObj(instr);
}

void InGame_ObjMan::UpdateFromSubject(PAT_Subject* changedSubject)
{
	PAT_GameObject* deleteGameObject = nullptr;
	PAT_Subject* deleteSubject = nullptr;

	deleteGameObject = nullptr;
	deleteSubject = nullptr;

	deleteSubject = mSubjectlist.Remove(deleteSubject);

	if(deleteSubject)
	{
		//Check if it's a game object
		deleteGameObject =
			dynamic_cast<PAT_GameObject*>(deleteSubject);
		if(deleteGameObject)
		{
			RemoveFromLists(deleteGameObject);
		}

		delete deleteSubject;
	}
}
