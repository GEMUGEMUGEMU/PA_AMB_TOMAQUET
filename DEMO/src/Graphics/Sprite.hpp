/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: Sprite.hpp
*  Purpose:
*  Creation Date: 24-04-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Sprite_hpp
#define Sprite_hpp

#include "PAT_Component.hpp"

struct Sprite : public ECS::PAT_Component<Sprite>
{
	Sprite();
	~Sprite();
};

#endif /* Sprite_hpp */
