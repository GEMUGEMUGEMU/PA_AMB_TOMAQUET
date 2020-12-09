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
	void Init(SDL_Renderer * render) override;
	void Update(float deltaTime) override;
	void Draw(SDL_Renderer * render) override;
};

#endif /* PauseScene_h */
