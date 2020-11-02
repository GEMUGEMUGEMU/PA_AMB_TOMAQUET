/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Scene.h
*  Purpose:
*  Creation Date: 01-11-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Scene_h
#define Scene_h

#include "Controller.h"
#include "SDL2/SDL.h"

class Scene
{
public:
	Scene() : mSceneController(nullptr){}
	virtual ~Scene(){}
	virtual void Init(SDL_Renderer * render){}
	virtual void Update(float deltaTime){}
	virtual void Draw(SDL_Renderer * render){}

	virtual Controller* GetController(){ return nullptr; }


protected:
	Controller* mSceneController;
};

#endif /* Scene_h */