/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_GameSystem.hpp
*  Purpose:
*  Creation Date: 18-03-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_GameSystem_hpp
#define PAT_GameSystem_hpp


struct PAT_GameSystem
{
	virtual ~PAT_GameSystem() explicit;
	virtual void Update() = 0;

};

#endif /* PAT_GameSystem_hpp */
