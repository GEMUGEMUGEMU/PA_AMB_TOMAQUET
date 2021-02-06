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

#include "PAT_Scene.h"
#include "LinkedList.h"
#include "GraphicObject.h"
#include "UpdateObject.h"
//#include "DemoSceneController.h"


class DemoScene : public PAT_Scene
{
public:
	DemoScene(){}
	~DemoScene();
	void Init(SDL_Renderer * render) override;
	void Update(float deltaTime) override;
	void Draw(SDL_Renderer * render) override;
	void Input(SDL_Event * event) override;

private:
	LinkedList<GraphicObject> mGraphicObjectsList;
	LinkedList<UpdateObject> mUpdateObjectsList;
};

#endif /* DemoScene_h */
