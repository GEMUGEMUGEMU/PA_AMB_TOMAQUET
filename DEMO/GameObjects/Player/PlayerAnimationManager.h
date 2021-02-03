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

#include "PAT_AnimationManager.h"
//#include "SDL2/SDL_image.h"
//#include "PlayerAIdle.h"
//#include "PAT_Animation.h"
#include "P_A_Move.h"
#include "PlayerAIdle.h"

class PlayerAnimationManager : public PAT_AnimationManager
{
public:
	PlayerAnimationManager();
	~PlayerAnimationManager();

	void Init(SDL_Renderer* render) override;
	void Draw(int x, int y, PAT_Animation& animation) override;
	void Update(PAT_Animation& animation) override;
	PlayerAIdle mAIdle;
	P_A_Move mAMove;
	//PAT_Animation mAPunch;

};
#endif /* PlayerAnimationManager_h */
