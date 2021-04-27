/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_System.hpp
*  Purpose: SDL2 adapter
*  Creation Date: 23-03-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_System_hpp
#define PAT_System_hpp

#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"
#include <stdint.h>
#include "PAT_Renderer.hpp"


#ifdef DEBUG_MODE
#include <iostream>
#endif


struct PAT_System
{
	enum STATUS{OK, E_INIT_VIDEO, E_INIT_IMG, E_UNINT};

	static STATUS Init()
	{
		if(SDL_InitSubSystem( SDL_INIT_VIDEO ) < 0 )
		{
#ifdef DEBUG_MODE
			std::cout << "Error SDL VIDEO initialization: "
				<< std::endl;
			std::cout << SDL_GetError() << std::endl;
#endif
			return E_INIT_VIDEO;
		}

		int imgFlags = IMG_INIT_PNG;
		/*
		   IMG_INIT_PNG is 2. If you init with IMG_INIT_PNG and
		   get bacK IMG_INIT_PNG you get 2 & 2 which is 2.
		   2 will evaluate to true
		*/
		if(!(IMG_Init(imgFlags) & imgFlags))
		{
			return E_INIT_IMG;
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

	static SDL_Texture* LoadTexture(PAT::Renderer* pRenderer, const char* pFilePath)
	{
//		if(pRenderer == nullptr || pFilePath == nullptr)
//		{
//			return Status::INVALID_ARGS;
//		}

		SDL_Surface * t_surface = IMG_Load(pFilePath);
//		if(t_surface == nullptr)
//		{
//#ifdef DEBUG_MODE
//			std::cout << "PAT_Sprite: Error in SDL Surface initialization: nullptr"
//				<< std::endl;
//			std::cout << SDL_GetError() << std::endl;
//#endif
//
//			return Status::LOAD_FILE_E;
//		}



		SDL_Texture* mSprite =
			SDL_CreateTextureFromSurface(pRenderer->mAdapter.mRenderer, t_surface);

		SDL_FreeSurface(t_surface);

		return mSprite;
	}

};

#endif /* PAT_System_hpp */
