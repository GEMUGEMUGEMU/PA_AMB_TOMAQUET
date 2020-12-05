/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: DemoSceneController.h
*  Purpose:
*  Creation Date: 01-11-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef DemoSceneController_h
#define DemoSceneController_h

#include "Controller.h"
#include "Player.h"
enum COMMAND_TYPE
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	PAUSE,
	QUIT
};


class DemoSceneController : public Controller
{
public:
	DemoSceneController(){}
	~DemoSceneController();
	/*COMMAND_TYPE*/ void  ManageInput(SDL_Event * event);

	void SetPlayer(Player * player){ mPlayer = player; }

private:
	Player* mPlayer = nullptr;
};

#endif /* DemoSceneController_h */
