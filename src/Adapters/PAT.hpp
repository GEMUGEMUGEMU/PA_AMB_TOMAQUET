/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT.hpp
*  Purpose: SDL2 adapter
*  Creation Date: 23-03-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_hpp
#define PAT_hpp

#include "SDL2/SDL.h"
#include <stdint.h>

#ifdef DEBUG_MODE
#include <iostream>
#endif


struct PAT
{
	enum STATUS{OK, E_INIT_VIDEO, E_UNINT};

	static STATUS Init()
	{
		if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
		{
#ifdef DEBUG_MODE
			std::cout << "Error SDL VIDEO initialization: "
				<< std::endl;
			std::cout << SDL_GetError() << std::endl;
#endif
			return E_INIT_VIDEO;
		}

		return OK;
	}

	static STATUS WasInit()
	{
		if(SDL_WasInit(SDL_INIT_VIDEO) !=0 )
		{

			return OK;
		}
		else
		{
#ifdef DEBUG_MODE
			std::cout << "E_UNINT: " << E_UNINT << std::endl;
#endif
			return E_UNINT;
		}
	}


	static void Delay(uint32_t milliSecondsDelay)
	{
		SDL_Delay(milliSecondsDelay);
	}

	static uint32_t GetTicks()
	{
		return SDL_GetTicks();
	}

	static void Quit()
	{
		SDL_VideoQuit();
		SDL_Quit();
	}

};

#endif /* PAT_hpp */
