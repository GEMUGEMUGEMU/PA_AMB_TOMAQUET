/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PAT_Scene.h
*  Purpose:
*  Creation Date: 10-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Scene_h
#define PAT_Scene_h

#include "SDL2/SDL.h"

class Controller;

class PAT_Scene
{
public:
	PAT_Scene(){}
	virtual ~PAT_Scene(){}
	virtual void Init(SDL_Renderer * render) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Draw(SDL_Renderer * render) = 0;

	Controller* GetController()
	{
		if(mController == nullptr)
		{
			return nullptr;
		}
		else
		{
			return mController;
		}
	}

protected:
/*
	WARNING: delete mController in derived classes deconstructor
*/
	Controller* mController = nullptr;
};



#endif /* PAT_Scene_h */
