/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Demo.hpp
*  Purpose:
*  Creation Date: 06-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Demo_hpp
#define Demo_hpp

#include "PAT_Game.hpp"

class Demo : public PAT_Game
{
public:
	Demo(){};
	~Demo();
	bool Init(uint32_t width, uint32_t height, const char* windowName);

};

#endif /* Demo_hpp */
