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

class PAT_Scene
{
public:
	PAT_Scene(){}
	virtual ~PAT_Scene()
	{
		delete(mController);
	}
	virtual void Init(SDL_Renderer * render) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Draw(SDL_Renderer * render) = 0;
	virtual void Input(SDL_Event * event) = 0;

//	Controller* GetController()
//	{
//		if(mController == nullptr)
//		{
//			return nullptr;
//		}
//		else
//		{
//			return mController;
//		}
//	}

protected:
//	Controller* mController = nullptr;
	PAT_Controller* mController;
};



#endif /* PAT_Scene_hpp */
