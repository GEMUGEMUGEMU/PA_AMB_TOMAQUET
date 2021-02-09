/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: DemoScene.hpp
*  Purpose:
*  Creation Date: 01-11-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef DemoScene_hpp
#define DemoScene_hpp

#include "PAT_Scene.hpp"
#include "PAT_LinkedList.hpp"
#include "PAT_GraphicObject.hpp"
#include "PAT_UpdateObject.hpp"
//#include "DemoSceneController.hpp"


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
	PAT_LinkedList<PAT_GraphicObject> mGraphicObjectsList;
	PAT_LinkedList<PAT_UpdateObject> mUpdateObjectsList;
};

#endif /* DemoScene_h */
