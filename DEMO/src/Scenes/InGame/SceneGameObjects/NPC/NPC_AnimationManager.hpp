/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: NPC_AnimationManager.hpp
*  Purpose:
*  Creation Date: 12-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef NPC_AnimationManager_hpp
#define NPC_AnimationManager_hpp

#include "PAT_AnimationManager.hpp"
#include "NPC_A_Idle.hpp"

class NPC_AnimationManager: public PAT_AnimationManager
{
public:
	NPC_AnimationManager();
	~NPC_AnimationManager();

	void Init(SDL_Renderer* render) override;
	void Draw(int x, int y, PAT_Animation& animation) override;
	PAT_ANIMATION_STATE Update(PAT_Animation& animation) override;

	NPC_A_Idle mAIdle;
};
#endif /* NPC_AnimationManager_hpp */
