/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: InGameScene.hpp
*  Purpose:
*  Creation Date: 01-11-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef InGameScene_hpp
#define InGameScene_hpp

#include "PAT_Scene.hpp"
#include "PAT_LinkedList.hpp"
#include "PAT_GraphicObject.hpp"
#include "PAT_UpdateObject.hpp"
#include "InGame_ObjMan.hpp"

class InGameScene : public PAT_Scene
{
public:
	InGameScene(){}
	~InGameScene();
	void Init(SDL_Renderer * renderer) override;
	void Update(float deltaTime) override;
	void Draw(SDL_Renderer * renderer) override;
	void Input(SDL_Event * event) override;
	PAT_Scene* GetSceneToPush() override;

private:
	InGame_ObjMan mGameObjsManager;
};

#endif /* InGameScene_h */
