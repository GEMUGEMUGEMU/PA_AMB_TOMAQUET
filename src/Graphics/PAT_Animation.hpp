/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Animation.hpp
*  Purpose: Abstract class for animations
*  Creation Date: 28-01-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Animation_hpp
#define PAT_Animation_hpp

#include "SDL2/SDL.h"
#include "PAT_LinkedList.hpp"

enum PAT_STATE_ANIMATION
{
	ANIMATION_FINISHED,
	IN_ANIMATION
};

class PAT_Animation
{
public:
	PAT_Animation() { }
	virtual ~PAT_Animation(){}

	void Init(SDL_Renderer* renderer);
	void Draw(int x, int y, SDL_Renderer* renderer);
	//void UpdateFrame();
	PAT_STATE_ANIMATION UpdateFrame();
	void ResetAnimation();

protected:
	virtual void LoadImage(SDL_Renderer* renderer) = 0;
	virtual void LoadClips() = 0;

	uint32_t mWith, mHeight;
	uint32_t mFramesNumber;
	uint32_t mSpriteIndex = 0;
	uint32_t mFrameCounter = 0;
	const uint32_t FRAMES_PER_CLIP = 30;

	PAT_LinkedList<SDL_Rect> mClipList;
	SDL_Texture* mAnimationSheet;
};

#endif /* PAT_Animation_hpp */
