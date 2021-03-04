/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: SceneManager.hpp
*  Purpose:
*  Creation Date: 06-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include "PAT_SceneManager.hpp"
#include "PAT_Observer.hpp"

class SceneManager : public PAT_SceneManager
{
public:
	SceneManager();
	~SceneManager();
	void Init(SDL_Renderer* renderer) override;
	void Input(SDL_Event * event) override;
	void UpdateFromSubject(PAT_Subject* changedSubject) override;
};

#endif /* SceneManager_hpp */
