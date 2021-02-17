/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: Commands.hpp
*  Purpose:
*  Creation Date: 11-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Commands_hpp
#define Commands_hpp

#include "PAT_GraphicStaticObject.hpp"
#include "PAT_Vector2D.hpp"

class Commands : public PAT_GraphicStaticObject
{
public:
	Commands(PAT_Vector2D position, SDL_Renderer* pRenderer);
	~Commands();

	void Draw(SDL_Renderer* pRenderer) override;

	PAT_Vector2D mPosition;
};



#endif /* Commands_hpp */
