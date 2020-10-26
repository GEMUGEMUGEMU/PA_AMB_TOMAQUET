/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Test2AnimationManager.h
*  Purpose:
*  Creation Date: 21-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Test2AnimationManager_h
#define Test2AnimationManager_h

#include "AnimationManager.h"

class Test2AnimationManager : public AnimationManager
{
public:
	Test2AnimationManager() : AnimationManager(){}
	~Test2AnimationManager(){}

protected:
	void LoadImage(SDL_Renderer* render);
	void LoadClips();

};



#endif /* Test2AnimationManager_h */
