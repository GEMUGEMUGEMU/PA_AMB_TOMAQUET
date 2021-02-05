/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: P_A_Punch.h
*  Purpose:
*  Creation Date: 04-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef P_A_Punch_h
#define P_A_Punch_h

#include "PAT_Animation.h"

class P_A_Punch : public PAT_Animation
{
public:
	P_A_Punch();
	~P_A_Punch();

protected:
	void LoadImage(SDL_Renderer* render);
	void LoadClips();
};


#endif /* P_A_Punch_h */
