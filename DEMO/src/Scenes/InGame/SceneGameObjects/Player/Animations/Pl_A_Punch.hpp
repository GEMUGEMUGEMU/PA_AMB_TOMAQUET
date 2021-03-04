/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: Pl_A_Punch.hpp
*  Purpose:
*  Creation Date: 04-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Pl_A_Punch_hpp
#define Pl_A_Punch_hpp

#include "PAT_Animation.hpp"

class Pl_A_Punch : public PAT_Animation
{
public:
	Pl_A_Punch();
	~Pl_A_Punch();

protected:
	void LoadImage(SDL_Renderer* render);
	void LoadClips();
};


#endif /* Pl_A_Punch_h */
