/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PAT_SceneManager.hpp
*  Purpose: Manages every Scene in game
*  Creation Date: 04-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_SceneManager_hpp
#define PAT_SceneManager_hpp

#include "SDL2/SDL.h"
#include "PAT_Scene.hpp"
#include "PAT_Stack.hpp"
#include "PAT_Observer.hpp"

class PAT_SceneManager : public PAT_Observer
{
public:
	PAT_SceneManager(){}
	virtual ~PAT_SceneManager()
	{
		//mActualScene is a pointer of the scen on top of the stack
		//so it's stack who's going to delete its scenes
		mActualScene = nullptr;
		SDL_DestroyRenderer(mRender);
	}

	virtual void Init(SDL_Renderer* renderer) = 0;

	bool IsEmpty();

	void PopScene();
	void PushScene(PAT_Scene * newScene);
	void InitAndPushScene(PAT_Scene * newScene);

	void Update(double deltaTime);
	void Draw(SDL_Renderer * render);
	void Render();
	void PopOrPushScene();
	virtual void Input(SDL_Event * event) = 0;

protected:
	PAT_Scene * mActualScene;
	SDL_Renderer * mRender;
	PAT_Stack<PAT_Scene> mStackScene;
};

#endif /* PAT_SceneManager_hpp */
