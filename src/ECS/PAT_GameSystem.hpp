/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_GameSystem.hpp
*  Purpose:
*  Creation Date: 18-03-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_GameSystem_hpp
#define PAT_GameSystem_hpp

#include "PAT_GameContext.hpp"

struct PAT_GameSystem
{
	virtual ~PAT_GameSystem() = default;
	virtual void Update(ECS::PAT_GameContext* pGameContext) = 0;
};

#endif /* PAT_GameSystem_hpp */
