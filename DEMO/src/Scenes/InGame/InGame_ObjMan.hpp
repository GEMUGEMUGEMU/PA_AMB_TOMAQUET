/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: InGame_ObjMan.hpp
*  Purpose:
*  Creation Date: 14-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef InGame_ObjMan_hpp
#define InGame_ObjMan_hpp

#include "PAT_GameObjectsManager.hpp"
#include "PAT_Observer.hpp"


class InGame_ObjMan : public PAT_GameObjectsManager, public PAT_Observer
{
public:
	InGame_ObjMan();
	~InGame_ObjMan();
	void Init(SDL_Renderer * renderer) override;
	void UpdateFromSubject(PAT_Subject* changedSubject) override;

private:
	PAT_LinkedList<PAT_Subject> mSubjectlist;
};

#endif /* InGame_ObjMan_hpp */
