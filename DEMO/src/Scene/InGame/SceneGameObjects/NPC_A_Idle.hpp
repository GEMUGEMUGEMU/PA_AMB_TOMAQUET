/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: NPC_A_Idle.hpp
*  Purpose:
*  Creation Date: 12-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef NPC_A_Idle_hpp
#define NPC_A_Idle_hpp

#include "PAT_Animation.hpp"

class NPC_A_Idle : public PAT_Animation
{
public:
	NPC_A_Idle();
	~NPC_A_Idle();


protected:
	void LoadImage(SDL_Renderer* render);
	void LoadClips();
};


#endif /* NPC_A_Idle_hpp */
