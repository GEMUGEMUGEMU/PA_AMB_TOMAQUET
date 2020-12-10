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

#include "PAT_SceneManager.h"

class DemoSceneManager : public PAT_SceneManager
{
public:
	DemoSceneManager(){}
	~DemoSceneManager();
	void Init(SDL_Renderer* renderer) override;

};

#endif /* DemoSceneManager_h */
