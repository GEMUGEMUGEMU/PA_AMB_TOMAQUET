/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: Pl_A_Idle.hpp
*  Purpose:
*  Creation Date: 28-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Pl_A_Idle_hpp
#define Pl_A_Idle_hpp

#include "PAT_Animation.hpp"

class Pl_A_Idle : public PAT_Animation
{
public:
	Pl_A_Idle();
	~Pl_A_Idle();


protected:
	void LoadImage(SDL_Renderer* render);
	void LoadClips();
};

#endif /* Pl_A_Idle_hpp */
