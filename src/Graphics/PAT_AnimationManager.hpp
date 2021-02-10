/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PAT_AnimationManager.hpp
*  Purpose:
*  Creation Date: 03-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_AnimationManager_hpp
#define PAT_AnimationManager_hpp

#include "SDL2/SDL.h"
#include "PAT_Animation.hpp"

class PAT_AnimationManager
{
public:
	PAT_AnimationManager() { };
	virtual ~PAT_AnimationManager(){ }

	virtual void Init(SDL_Renderer* render) = 0;
	virtual void Draw(int x, int y, PAT_Animation& animation) = 0;
	virtual PAT_ANIMATION_STATE Update(PAT_Animation& animation) = 0;

protected:
	SDL_Renderer* mRender;
};
#endif /* PAT_AnimationManager_hpp */
