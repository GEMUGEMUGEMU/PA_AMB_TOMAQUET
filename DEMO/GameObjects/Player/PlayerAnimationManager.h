/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PlayerAnimationManager.h
*  Purpose:
*  Creation Date: 17-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PlayerAnimationManager_h
#define PlayerAnimationManager_h

#include "AnimationManager.h"
#include "SDL2/SDL_image.h"

class PlayerAnimationManager : public AnimationManager
{
public:
	PlayerAnimationManager() : AnimationManager(){}
	~PlayerAnimationManager()
	{
		SDL_DestroyTexture(mAnimationSheet);
	}

protected:
	void LoadImage(SDL_Renderer* render)
	{
		const char* filePath= "./Sprites/Prehistoric.png";

		SDL_Surface * tempSurface = IMG_Load(filePath);

		mWith = tempSurface->w;
		mHeight = tempSurface->h;

		mAnimationSheet =SDL_CreateTextureFromSurface(render, tempSurface);

		SDL_FreeSurface(tempSurface);
	}

	void LoadClips()
	{
		SDL_Rect* clip1 = new SDL_Rect;
		clip1->x = 0;
		clip1->y = 0;
		clip1->w = 64;
		clip1->h = 64;
		mClipList.Add(clip1);

		SDL_Rect* clip2 = new SDL_Rect;
		clip2->x = 64;
		clip2->y = 0;
		clip2->w = 64;
		clip2->h = 64;
		mClipList.Add(clip2);

		FRAMES_NUMBER = mClipList.GetSize();

	}



};
#endif /* PlayerAnimationManager_h */
