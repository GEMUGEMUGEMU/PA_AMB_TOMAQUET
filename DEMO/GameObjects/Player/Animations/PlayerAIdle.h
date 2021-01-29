/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PlayerAIdle.h
*  Purpose:
*  Creation Date: 28-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PlayerAIdle_h
#define PlayerAIdle_h

#include "PAT_Animation.h"

class PlayerAIdle : public PAT_Animation
{
public:
	PlayerAIdle();
	~PlayerAIdle();


protected:
	void LoadImage(SDL_Renderer* render);
	void LoadClips();
};

#endif /* PlayerAIdle_h */
