/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Sprite.cpp
*  Purpose:
*  Creation Date: 25-04-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "PAT_Sprite.hpp"
#include "PAT_System.hpp"

namespace PAT
{

Sprite::Sprite()
{
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(mSprite);
}

PAT::Status Sprite::InitSprite(Renderer* pRenderer, const char* pFilePath)
{
	if(pRenderer == nullptr || pFilePath == nullptr)
	{
		return Status::INVALID_ARGS;
	}

	SDL_Surface * t_surface = IMG_Load(pFilePath);
	if(t_surface == nullptr)
	{
#ifdef DEBUG_MODE
		std::cout << "PAT_Sprite: Error in SDL Surface initialization: nullptr"
			<< std::endl;
		std::cout << SDL_GetError() << std::endl;
#endif

		return Status::LOAD_FILE_E;
	}

	mSprite =
		SDL_CreateTextureFromSurface(pRenderer->mAdapter.mRenderer, t_surface);

	SDL_FreeSurface(t_surface);

	return PAT::Status::OK;
}

}
