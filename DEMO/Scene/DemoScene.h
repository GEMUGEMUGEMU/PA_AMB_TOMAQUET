/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: DemoScene.h
*  Purpose:
*  Creation Date: 01-11-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef DemoScene_h
#define DemoScene_h

#include "Scene.h"

class DemoScene : public Scene
{
public:
	void Init(SDL_Renderer * render);
	void Update(float deltaTime);
	void Draw(SDL_Renderer * render);
	Controller* GetController();

private:
	LinkedList<GraphicObject> mGraphicObjectsList;
	LinkedList<UpdateObject> mUpdateObjectsList;
};

#endif /* DemoScene_h */
