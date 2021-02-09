/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Pl_AnimationManager.hpp
*  Purpose:
*  Creation Date: 17-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Pl_AnimationManager_hpp
#define Pl_AnimationManager_hpp

#include "PAT_AnimationManager.hpp"
#include "Pl_A_Move.hpp"
#include "Pl_A_Punch.hpp"
#include "Pl_A_Idle.hpp"

class Pl_AnimationManager : public PAT_AnimationManager
{
public:
	Pl_AnimationManager();
	~Pl_AnimationManager();

	void Init(SDL_Renderer* render) override;
	void Draw(int x, int y, PAT_Animation& animation) override;
	PAT_STATE_ANIMATION Update(PAT_Animation& animation) override;

	Pl_A_Idle mAIdle;
	Pl_A_Move mAMove;
	Pl_A_Punch mAPunch;
};

#endif /* Pl_AnimationManager_hpp */
