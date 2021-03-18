/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_GameContext.hpp
*  Purpose:
*  Creation Date: 24-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_GameContext_hpp
#define PAT_GameContext_hpp

#include "PAT_ECSAlias.hpp"

namespace ECS
{
struct PAT_GameContext
{
	virtual ~PAT_GameContext() = default;
	virtual VecEntities& GetEntities() = 0;
};

}
#endif /* PAT_GameContext_hpp */
