/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: AnimationManager.h
*  Purpose:
*  Creation Date: 03-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef AnimationManager_h
#define AnimationManager_h

#include "SDL2/SDL.h"
#include "LinkedList.h"
#include "PAT_Animation.h"

class AnimationManager
{
public:
	AnimationManager();
	virtual ~AnimationManager(){ }

	virtual void Init(SDL_Renderer* render) = 0;
	void Draw(int x, int y, SDL_Renderer* renderer);
	void Update();

	PAT_Animation& mActualAnimation;
//protected:
//	virtual void LoadImage(SDL_Renderer* render){}
//	virtual void LoadClips(){}
//	uint32_t mWith, mHeight;
//	uint32_t FRAMES_NUMBER;
//	LinkedList<SDL_Rect> mClipList;
//	SDL_Texture* mAnimationSheet;

//private:
//	const uint32_t FRAMES_PER_CLIP = 30;
//	uint32_t mFrameCounte = 0;
//	uint32_t mSpriteIndex = 0;
};

#endif /* AnimationManager_h */
