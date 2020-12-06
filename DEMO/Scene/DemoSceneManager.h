/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: DemoSceneManager.h
*  Purpose:
*  Creation Date: 06-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef DemoSceneManager_h
#define DemoSceneManager_h

#include "SceneManager.h"

class DemoSceneManager : public SceneManager
{
public:
	DemoSceneManager(){}
	~DemoSceneManager();
	void Init(SDL_Renderer* renderer) override;

};

#endif /* DemoSceneManager_h */
