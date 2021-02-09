/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: Pl_A_Move.hpp
*  Purpose:
*  Creation Date: 30-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Pl_A_Move_hpp
#define Pl_A_Move_hpp

#include "PAT_Animation.hpp"

class Pl_A_Move : public PAT_Animation
{
public:
	Pl_A_Move();
	~Pl_A_Move();

protected:
	void LoadImage(SDL_Renderer* render);
	void LoadClips();
};


#endif /* Pl_A_Move_hpp */
