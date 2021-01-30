/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PlayerAnimationManager.h
*  Purpose:
*  Creation Date: 17-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PlayerAnimationManager_h
#define PlayerAnimationManager_h

#include "AnimationManager.h"
#include "SDL2/SDL_image.h"
#include "PlayerAIdle.h"

class PlayerAnimationManager : public AnimationManager
{
public:
	PlayerAnimationManager();
	~PlayerAnimationManager();

	void Init(SDL_Renderer* render) override;
};
#endif /* PlayerAnimationManager_h */
