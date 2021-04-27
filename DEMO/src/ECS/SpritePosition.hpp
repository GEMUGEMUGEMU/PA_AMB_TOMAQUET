/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: SpritePosition.hpp
*  Purpose: Where to draw enity sprite
*  Creation Date: 07-05-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef SpritePosition_hpp
#define SpritePosition_hpp
#include "PAT_System.hpp"
#include "PAT_Component.hpp"

struct SpritePosition : public ECS::PAT_Component<SpritePosition>
{
	SpritePosition(ECS::EntityID pEID);
	~SpritePosition();
	//SDL_Rect* mSpritePos {nullptr};
	SDL_Rect mSpritePos;// {0,0,64,64};
};

#endif /* SpritePosition_hpp */
