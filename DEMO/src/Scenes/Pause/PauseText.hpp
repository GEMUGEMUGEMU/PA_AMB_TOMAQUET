/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PauseText.hpp
*  Purpose: Show "PAUSE" text when pause
*  Creation Date: 10-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PauseText_hpp
#define PauseText_hpp

#include "PAT_GraphicStaticObject.hpp"
#include "PAT_Vector2D.hpp"

class PauseText : public PAT_GraphicStaticObject
{
public:
	PauseText(PAT_Vector2D position, SDL_Renderer* pRenderer);
	~PauseText();

	void Draw(SDL_Renderer* pRenderer) override;

	PAT_Vector2D mPosition;
};

#endif /* PauseText_hpp */
