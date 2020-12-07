/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Demo.h
*  Purpose:
*  Creation Date: 06-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Demo_h
#define Demo_h

#include "PTA_Game.h"

class Demo : public PTA_Game
{
public:
	Demo(){};
	~Demo();

	bool Init(uint32_t width, uint32_t height,
			const char* windowName) override;

};

#endif /* Demo_h */
