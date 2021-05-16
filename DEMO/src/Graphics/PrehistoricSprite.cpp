/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PrehistoricSprite.cpp
*  Purpose:
*  Creation Date: 03-05-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "PrehistoricSprite.hpp"

PrehistoricSprite::PrehistoricSprite()
{
}

PrehistoricSprite::~PrehistoricSprite()
{
}



unsigned short int PrehistoricSprite::Init(/*SDL_Renderer*/PAT::Renderer* pRenderer)
{
	const char* file_path= "./sprites/Prehistoric0.png";

	return InitSprite(pRenderer, file_path);
}

