/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PTA_Scene.h
*  Purpose:
*  Creation Date: 10-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PTA_Scene_h
#define PTA_Scene_h

#include "SDL2/SDL.h"

class Controller;

class PTA_Scene
{
public:
	PTA_Scene(){}
	virtual ~PTA_Scene(){}
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



#endif /* PTA_Scene_h */
