/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Scene.h
*  Purpose:
*  Creation Date: 01-11-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Scene_h
#define Scene_h

#include "SDL2/SDL.h"

class Controller;

class Scene
{
public:
	Scene(){}
	virtual ~Scene(){}
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

#endif /* Scene_h */
