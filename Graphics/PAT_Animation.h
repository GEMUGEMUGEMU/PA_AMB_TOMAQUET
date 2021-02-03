/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Animation.h
*  Purpose: Abstract class for animations
*  Creation Date: 28-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Animation_h
#define PAT_Animation_h

#include "SDL2/SDL.h"
#include "LinkedList.h"

class PAT_Animation
{
public:
	PAT_Animation() { }
	virtual ~PAT_Animation(){}

	void Init(SDL_Renderer* render);
	void Draw(int x, int y, SDL_Renderer* renderer);
	void UpdateFrame();
	void ResetAnimation();


//	PAT_Animation& operator=(const PAT_Animation& animation);

protected:
	virtual void LoadImage(SDL_Renderer* render) = 0;
	virtual void LoadClips() = 0;

	uint32_t mWith, mHeight;
	uint32_t mFramesNumber;
	uint32_t mSpriteIndex = 0;
	uint32_t mFrameCounter = 0;
	const uint32_t FRAMES_PER_CLIP = 30;

	LinkedList<SDL_Rect> mClipList;
	SDL_Texture* mAnimationSheet;
};

#endif /* PAT_Animation_h */
