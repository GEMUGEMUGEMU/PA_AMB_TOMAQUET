/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: NPC_AnimationManager.cpp
*  Purpose:
*  Creation Date: 12-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "NPC_AnimationManager.hpp"

NPC_AnimationManager::NPC_AnimationManager() : PAT_AnimationManager() { }

NPC_AnimationManager::~NPC_AnimationManager() { }

void NPC_AnimationManager::Init(SDL_Renderer* renderer)
{
	mRenderer = renderer;

	mAIdle.Init(mRenderer);
}

//TODO: Why not to standarize these?
void NPC_AnimationManager::Draw(int x, int y, PAT_Animation& animation)
{
	animation.Draw(x, y, mRenderer);
}

PAT_ANIMATION_STATE NPC_AnimationManager::Update(PAT_Animation& animation)
{
	return animation.UpdateFrame();
}
