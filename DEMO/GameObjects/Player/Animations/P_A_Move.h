/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: P_A_Move.h
*  Purpose:
*  Creation Date: 30-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef P_A_Move_h
#define P_A_Move_h

#include "PAT_Animation.h"

class P_A_Move : public PAT_Animation
{
public:
	P_A_Move();
	~P_A_Move();


protected:
	void LoadImage(SDL_Renderer* render);
	void LoadClips();
};


#endif /* P_A_Move_h */
