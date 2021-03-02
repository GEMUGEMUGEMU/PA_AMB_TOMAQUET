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
//#include <memory>


class PAT_SceneManager : public PAT_Observer
{
public:
	PAT_SceneManager(){}
	virtual ~PAT_SceneManager()
	{
		//mpActualScene is a pointer of the scen on top of the stack
		//so it's stack who's going to delete its scenes
		mpActualScene = nullptr;
		SDL_DestroyRenderer(mpRenderer);
	}

	virtual void Init(SDL_Renderer* pRenderer) = 0;

	bool IsEmpty();

	void PopScene();
	void PushScene(PAT_Scene * pNewScene);
	void InitAndPushScene(PAT_Scene * pNewScene);

	void Update(double deltaTime);
	void Draw(SDL_Renderer * pRenderer);
	void Render();
	void PopOrPushScene();
	virtual void Input(SDL_Event * pEvent) = 0;

protected:
	PAT_Scene * mpActualScene;
//	std::unique_ptr<PAT_Scene> mpActualScene;
	SDL_Renderer * mpRenderer;
	PAT_Stack<PAT_Scene> mStackScene;
};

#endif /* PAT_SceneManager_hpp */
