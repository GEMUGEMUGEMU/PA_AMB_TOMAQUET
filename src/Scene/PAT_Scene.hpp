/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PAT_Scene.hpp
*  Purpose:
*  Creation Date: 10-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Scene_hpp
#define PAT_Scene_hpp

#include "SDL2/SDL.h"
#include "PAT_Controller.hpp"
#include "PAT_Subject.hpp"

enum PAT_SCENE_STATE
{
	CONTINUE, //Continue with this scene
	POP,
	PUSH_NEW_SCENE
};

class PAT_Scene: public PAT_Subject
{
public:
	PAT_Scene(){}
	virtual ~PAT_Scene()
	{
		delete(mController);
	}

	virtual void Init(SDL_Renderer * renderer) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Draw(SDL_Renderer * renderer) = 0;
	virtual void Input(SDL_Event * event) = 0;
	virtual PAT_Scene* GetSceneToPush() = 0;
	PAT_SCENE_STATE mState = CONTINUE;

protected:
	PAT_Controller* mController;
};

#endif /* PAT_Scene_hpp */
