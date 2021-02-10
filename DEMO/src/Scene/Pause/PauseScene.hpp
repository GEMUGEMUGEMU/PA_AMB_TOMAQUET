/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PauseScene.hpp
*  Purpose:
*  Creation Date: 07-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PauseScene_hpp
#define PauseScene_hpp

#include "PAT_Scene.hpp"
#include "PAT_LinkedList.hpp"
#include "PAT_GraphicObject.hpp"

class PauseScene : public PAT_Scene
{
public:
	PauseScene(){}
	~PauseScene();
	void Init(SDL_Renderer * render) override;
	void Update(float deltaTime) override;
	void Draw(SDL_Renderer * render) override;
	void Input(SDL_Event * event) override;
	PAT_Scene* GetSceneToPush() override;

private:
	PAT_LinkedList<PAT_GraphicObject> mGraphicObjectsList;
};

#endif /* PauseScene_hpp */
