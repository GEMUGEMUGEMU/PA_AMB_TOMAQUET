/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Test1AnimationManager.h
*  Purpose: 
*  Creation Date: 17-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Test1AnimationManager_h
#define Test1AnimationManager_h

#include "AnimationManager.h"

class Test1AnimationManager : public AnimationManager
{
public:
	Test1AnimationManager() : AnimationManager(){}
	~Test1AnimationManager(){}

protected:
	void LoadImage(SDL_Renderer* render);
	void LoadClips();

};


#endif /* Test1AnimationManager_h */
