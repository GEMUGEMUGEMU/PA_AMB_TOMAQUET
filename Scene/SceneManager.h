/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: SceneManager.h
*  Purpose: Manages every Scene in game
*  Creation Date: 04-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef SceneManager_h
#define SceneManager_h

#include "SDL2/SDL.h"
#include "Scene.h"
#include "Stack.h"
#include "Controller.h"

class SceneManager
{
public:
	SceneManager(){}
	~SceneManager(){}
	void Init(SDL_Renderer* renderer);
	Scene * GetActualScene();
	void PopScene();
	void PushScene(Scene * newScene);

	void Update(double deltaTime);
	void Draw(SDL_Renderer * render);
	void Render();
	void Input(SDL_Event * event);

private:
	Stack<Scene> mStackScene;
	Scene * mActualScene;
	Controller * mController;
	SDL_Renderer * mRender;
};

#endif /* SceneManager_h */
