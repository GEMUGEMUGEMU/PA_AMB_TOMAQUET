/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PauseScene.h
*  Purpose:
*  Creation Date: 07-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PauseScene_h
#define PauseScene_h

#include "Scene.h"

class PauseScene : public Scene
{
public:
	PauseScene(){}
	~PauseScene();
	void Init(SDL_Renderer * render);
	void Update(float deltaTime);
	void Draw(SDL_Renderer * render);
};

#endif /* PauseScene_h */
