/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Test2AnimationManager.h
*  Purpose:
*  Creation Date: 17-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Test2AnimationManager_h
#define Test2AnimationManager_h

#include "AnimationManager.h"
#include "SDL2/SDL_image.h"

class Test2AnimationManager : public AnimationManager
{
public:
	Test2AnimationManager() : AnimationManager(){}
	~Test2AnimationManager(){}

protected:
	void LoadImage(SDL_Renderer* render)
	{
		const char* filePath= "./Sprites/Prehistoric0.png";

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

#endif /* Test2AnimationManager_h */
