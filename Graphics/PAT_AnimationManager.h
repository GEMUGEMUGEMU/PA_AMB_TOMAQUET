/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PAT_AnimationManager.h
*  Purpose:
*  Creation Date: 03-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_AnimationManager_h
#define PAT_AnimationManager_h

#include "SDL2/SDL.h"
//#include "LinkedList.h"
#include "PAT_Animation.h"

class PAT_AnimationManager
{
public:
	PAT_AnimationManager() { };
	virtual ~PAT_AnimationManager(){ }

	virtual void Init(SDL_Renderer* render) = 0;
//	void Draw(int x, int y, SDL_Renderer* renderer);
	virtual void Draw(int x, int y, PAT_Animation& animation) = 0;
	virtual void Update(PAT_Animation& animation) = 0;
//	void SetAnimation(PAT_Animation* newAnimation);

//	PAT_Animation* mActualAnimation = nullptr;

protected:
	SDL_Renderer* mRender;
};
#endif /* PAT_AnimationManager_h */
