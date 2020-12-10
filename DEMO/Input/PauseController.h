/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PauseController.h
*  Purpose:
*  Creation Date: 07-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PauseController_h
#define PauseController_h

#include "Controller.h"

class PauseController : public Controller
{
public:
	PauseController(){}
	~PauseController(){}
	void  ManageInput(SDL_Event * event, PTA_Scene *& nextScene,
		bool * haveToPop) override;
};

#endif /* PauseController_h */
