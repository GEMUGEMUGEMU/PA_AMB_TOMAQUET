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

#include "PAT_Scene.h"
#include "LinkedList.h"
#include "GraphicObject.h"

class PauseScene : public PAT_Scene
{
public:
	PauseScene(){}
	~PauseScene();
	void Init(SDL_Renderer * render) override;
	void Update(float deltaTime) override;
	void Draw(SDL_Renderer * render) override;
	void Input(SDL_Event * event) override;

private:
	LinkedList<GraphicObject> mGraphicObjectsList;
};

#endif /* PauseScene_h */
