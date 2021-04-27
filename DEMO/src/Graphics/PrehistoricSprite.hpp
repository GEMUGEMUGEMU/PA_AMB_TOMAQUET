/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PrehistoricSprite.hpp
*  Purpose:
*  Creation Date: 03-05-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PrehistoricSprite_hpp
#define PrehistoricSprite_hpp
#include "PAT_Sprite.hpp"
#include "PAT_Renderer.hpp"
#include "PAT_Status.hpp"

struct PrehistoricSprite : public PAT::Sprite
{
	PrehistoricSprite();
	~PrehistoricSprite();

	unsigned short int Init(/*SDL_Renderer*/PAT::Renderer* pRenderer);


	//SDL_Texture* getTexture() override;
	//SDL_Rect* getClip() override;

	//SDL_Texture* mTexture;// {nullptr};
	//SDL_Rect* clip1;// {nullptr};

};

#endif /* PrehistoricSprite_hpp */
